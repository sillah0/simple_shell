#include "shell.h"

/**
 * main - the entry point
 *@ac: no of command line arguments
 *@argv: array of character pointers of the command line argument
 *@envp: array of character pointers of the environment variables
 *
 * Return: 0 on success
 */

int main(int ac, char *argv[], char **envp)
{
	char *prompt = "$ ", *buf = NULL, **new_argv;
	size_t size_buf = 0;
	ssize_t line_r = 0;
	int exit_status = 0;
	pid_t pid = 0;
	char pathname[1024] = {'\0'}, *pathname_ptr = pathname, *_pathname;

	check_usage(ac);
	exit_status = 0;
	while (1)
	{
		_prompt(prompt);
		line_r = _getline(&buf, &size_buf, STDIN_FILENO);
		if (line_r == -1)
		{
			_prompt2();
			free(buf);
			break;
		}
		buf[line_r - 1] = '\0';
		new_argv = tokenize(buf);
		handle_builtin(new_argv[0], argv, buf, new_argv, exit_status);
		if (new_argv[0] != NULL)
		{
			pathname_ptr = pathname;
			_pathname = handle_path(new_argv[0], &pathname_ptr);
			if (_pathname != NULL)
				new_argv[0] = pathname;
			else
			{
				cmd_not_found(argv, new_argv, &exit_status);
				continue;
			}
			_execute(pid, buf, argv, new_argv, envp, &exit_status);
		}
		else
			_free(new_argv);
	}
	return (exit_status);
}

/**
 * execute - executes a command using the execve system call
 * @buf: the input buffer containing the command to be executed
 * @av: the name of the shell program
 * @new_argv: an array of character pointers representing the tokenized command
 * @envp: an array of character pointers representing the environment variables
 *
 * Return: void
 */

void execute(char *buf, char *av, char **new_argv, char **envp)
{
	int val = 0;

	val = execve(new_argv[0], new_argv, envp);

	if (val == -1)
	{
		printf("val = %d\n", val);
		perror(av);
		free(buf);
		free(new_argv);
		exit(2);

	}

}

/**
 * _execute - creates a child process to execute a command
 * @pid: the process ID of the child process
 * @buf: the input buffer containing the command to be executed
 * @argv: an array of character pointers representing
 *	the command line arguments
 * @new_argv: an array of character pointers representing
 *	the tokenized command
 * @envp: an array of character pointers representing
 *	the environment variables
 * @exit_status: a pointer to an integer representing
 *	the exit status of the command
 *
 * Return: void
 */

void _execute(pid_t pid, char *buf, char **argv, char **new_argv,
		char **envp, int *exit_status)
{

	int wstatus;

	pid = fork();
	if (pid == 0)
	{
		execute(buf, argv[0], new_argv, envp);
	}
	else
	{
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			*exit_status = WEXITSTATUS(wstatus);
		}
		free(new_argv);
		new_argv = NULL;
	}
}

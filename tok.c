#include "shell.h"

/**
 * tokenize - a function to tokenize a string
 * @buf: the input string to be tokenized
 *
 * Return: a pointer to an array of char argv
 */

char **tokenize(char *buf)
{
	int i;
	char *delim = " ";
	char *token = NULL;
	int argc = count_delim(buf, ' ') + 1;
	char **argv;

	argv = malloc(sizeof(char *) * (argc + 1));
	token = strtok(buf, delim);
	i = 0;

	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;

	}
	argv[i] = NULL;

	return (argv);
}

#include "shell.h"

/**
 * _atoi - Convert a string to an integer
 * @s: string pointer input
 *
 * Return: int
 */

int _atoi(char *s)
{
	unsigned int num, result = 0;
	int sign = 1;
	char *ptr = s;

	while (*ptr != '\0' && (*ptr < '0' || *ptr > '9'))
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}

	ptr = s;
	while (*ptr != '\0' && (*ptr >= '0' && *ptr <= '9'))
	{
		num = *ptr  - '0';
		result = result * 10 + num;
		ptr++;
	}

	if (*ptr != '\0')
		return (-1);
	return (sign * result);

}
/**
 * _memset - function fills the first n bytes of the memory area
 *	with a character
 *@s: a charcter pointer
 *@b: a character to fill the memory block with.
 *@n: an integer
 *
 * Return: a character pointer to the filled memory
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *str = s;
	unsigned int index1;

	for (index1 = 0; index1 < n; index1++)
	{
		*str = b;
		str++;
	}

	return (s);
}
/**
 * _putchar - it writes the character c to stdout
 * @c: The character to be printed
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *_realloc -  a function that reallocates a memory block using malloc and free
 *@ptr: a pointer to a prevoiusly allocated memory block with malloc
 *@old_size: the initial size of the allocated memory block
 *@new_size: the new size of what ptr is pointing to
 *
 * Return: an integer pointer to the newly resized memory block.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	unsigned char *p = ptr, *pp = ptr;
	unsigned int i, flag, len;

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	else if (ptr && !new_size)
	{
		free(ptr);
		return (NULL);
	}
	else if (old_size == new_size)
	{
		return (ptr);
	}
	else
	{
		pp = malloc(new_size);

		if (p != pp)
			flag = 1;

		len = old_size < new_size ?
			old_size : new_size;
		for (i = 0; i < len; i++)
			*pp++ = (unsigned char) *p++;

		if (flag)
			free(ptr);
	}
	return ((void *) (pp - len));
}

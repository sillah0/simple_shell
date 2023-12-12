#include "shell.h"

/**
 * int_to_str - Converts an integer to string
 *
 * @n: integer to be converted
 *
 * @s: a pointer to where the srtring will be stored
 *
 * Return : nothing
 */

void int_to_str(int n, char *s)
{
	unsigned int divisor = 1, digit, num = n;
	int i;

	while (num / divisor >= 10)
		divisor *= 10;

	i = 0;
	while (divisor != 0)
	{
		digit = num / divisor;
		s[i] = digit + '0';
		num = num % divisor;
		divisor /= 10;
		i++;
	}
	s[i] = '\0';
}

/**
 * count_delim - counts the number of times a delimitor occurs
 * @str: the input string to be searched
 * @delim: the delimiter character to search for
 *
 * Return: something
 */

int count_delim(char *str, char delim)
{
	int count = 0;
	int i;

	if (str[0] == '\0')
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == delim)
			count++;
	}
	return (count);
}

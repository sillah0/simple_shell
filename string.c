#include "shell.h"


/**
 * _strcat - a function to concatenates two string
 *@dest: the string concatenated to be return
 *@src: the source string to be appended to the end of dest
 *
 * Return: char *
 */

char *_strcat(char *dest, char *src)
{
	int i, len_dest = _strlen(dest);

	i = len_dest;
	for (; *src != '\0'; src++)
	{
		dest[i] = *src;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
/**
 *_strcmp - compare strings
 *@s1: the first string
 *@s2: the second string
 *
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	int diff = 0, index1;

	index1 = 0;
	while (s1[index1] != '\0' && s2[index1] != '\0')
	{
		diff = s1[index1] - s2[index1];

		if (diff == 0)
			index1++;
		else
			break;
	}

	return (diff);
}
/**
 * _strlen - a function that calculates the length of a string.
 * @s: pointer to the string.
 *
 * Return: void
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}
/**
 * _strstr - Find a substring in a string.
 * @haystack: A string to search for the substring.
 * @needle: The substring to find.
 *
 * Return: A pointer to the first occurrence of the substring
 *           in the haystack, or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	char *p1, *p2 = needle;

	for (p1 = haystack; *p1; p1++)
	{
		char *pp1 = p1;

		while (*pp1 == *p2 && *p2)
		{
			pp1++;
			p2++;
		}
		if (!*p2)
			return (p1);

		 p2 = needle;
	}
	return (NULL);
}

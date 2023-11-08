#include "main.h"

/**
 * _strncpy - copy a string.
 *
 * @dest: The destination string to be copied into.
 * @src: The source string.
 * @n: The amount of characters to be copied.
 *
 * Return: The combined string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, x;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		x = i;
		while (x < n)
		{
			dest[j] = '\0';
			x++;
		}
	}

	return (s);
}

/**
 * _strncat - combines two strings.
 *
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum of byts to be usedally used.
 *
 * Return: The combined string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, x;
	char *s = dest;

	i = 0;
	x = 0;
	while (dest[i] != '\0')
		i++;
	while (src[x] != '\0' && x < n)
	{
		dest[i] = src[x];
		i++;
		x++;
	}
	if (x < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - locates a character in a string
 *
 * @s: the string to be parsed
 * @c: the character to look for
 *
 * Return: a pointer to the first occurrence of the character 'c'
 * in the string 's', or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

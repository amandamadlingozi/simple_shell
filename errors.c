#include "main.h"

/**
 * _eputs - prints an input string.
 *
 * @str: The string to be printed out using _eputs.
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr.
 *
 * @c: The character to print.
 *
 * Return: 1 on Success. On error, -1 is ruturned,
 * and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;

	return (1);
}

/**
 * _putfd - write the character c into the given fd.
 *
 * @c: The charact to print.
 * @fd: The file description to write into.
 *
 * Return: 1 on Success. On error, -1 is returned
 * and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;

	return (1);
}

/**
 * _putsfd - prints an input string.
 *
 * @str: The string to be printed out.
 * fd: The file description to write into.
 *
 * Return: The number of chars put.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}

	return (i);
}

#include "main.h"

/**
 * is_cmd - determins if a file is an excutable command
 *
 * @info: information struct
 * @path: file path
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates charecters
 *
 * @pathstr: the PATH string
 * @start: Start indexing
 * @stop: stop indexing
 *
 * Return: pointer of a new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int h = 0, i = 0;

	for (i = 0, h = start; h < stop; h++)
		if (pathstr[h] != ':')
			buf[i++] = pathstr[h];
	buf[i] = 0;
	return (buf);
}

/**
 * find_path - find cmd PATH string
 *
 * @info: info struct
 * @pathstr: PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int h = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[h] || pathstr[h] == ':')
		{
			path = dup_chars(pathstr, curr_pos, h);
				if (!*path)
					_strcat(path, cmd);
				else
				{
					_strcat(path, "/");
					_strcat(path, cmd);
				}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[h])
				break;
			curr_pos = h;
		}
		h++;
	}
	return (NULL);
}

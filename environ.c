#include "main.h"

/**
 * _myenv - prints the current environment
 *
 * @info: Structure containing arguments.
 * This helps maintain the constant function prototype.
 *
 * Return: 0 Always
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);

	return (0);
}

/**
 * _getenv - get a value of an environ variable
 *
 * @info: Structure containing arguments.
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}

	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable
 * or modify an existing enviroment.
 *
 * @info: Structure containg arguments.
 * This helps maint the constant function prototype.
 *
 * Return: 0 Always
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		printf("Invalid number of arguements\n");

		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);

	return (1);
}

/**
 * _myunsetenv - Remove enviroment variable.
 *
 * @info: Structure containing arguements.
 * This helps maintain constant function prototype.
 *
 * Return: 0 Always
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		printf("Provided less arguements.\n");

		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - It populates the env linked list
 *
 * @info: Structure containing arguements.
 * This helps maintain a constant function prototype.
 *
 * Return: 0 Always
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;

	return (0);
}

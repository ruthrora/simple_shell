#include "shell.h"
/**
 * _myenv - prints the environment
 * @info: info about the arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - get value of environmen variable
 * @info: argument info
 * @name: name of the variable
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *s;

	while (node)
	{
		s = starts_with(node->str, name);
		if (s && *s)
			return (s);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - new environment variable
 * @info: info about potential arguments
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("incorrect number of arguments\n");
		return (1);
	}

	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - removes environment variable
 * @info: info about arguments
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int k;

	if (info->argc == 1)
	{

		_eputs("Too few arguments.\n");
		return (1);
	}

	for (k = 1; k <= info->argc; k++)
		_unsetenv(info, info->argv[k]);
	return (0);
}
/**
 * populate_env_list - populates env linked lists
 * @info: info about arguments
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t k;

	for (k = 0; environ[k]; k++)
		add_node_end(&node, environ[k], 0);

	info->env = node;
	return (0);
}

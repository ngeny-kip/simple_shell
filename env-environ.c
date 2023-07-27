#include "shell.h"

/**
 * currentEnv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int currentEnv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _envVar - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_envVar(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *ch;

	while (node)
	{
		ch = starts_with(node->str, name);
		if (ch && *ch)
			return (ch);
		node = node->next;
	}
	return (NULL);
}

/**
 * _newEnv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _newEnv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Less  number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _remEnv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _remEnv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populateEnvList - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populateEnvList(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}


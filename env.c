#include "hsh.h"
/**
 * _unsetenv - Remove an environment variable
 * @info: Structure
 * @tokens: tokens
 * Return: 2
 */
int _unsetenv(info_t *info, char **tokens)
{
	int i;

	if (!tokens[1])
	{
		printf("Too few arguements.\n");
		return (2);
	}
	else
	{
		for (i = 0; environ[i]; i++)
			if (environ[i][0] == tokens[1][0] && environ[i][1] ==
			 tokens[1][1] && environ[i][2] == tokens[1][2])
			{
				environ[i] = NULL;
				return (2);
			}
	}
	info->condition = 2;
	return (2);
}

/**
 * _setenv - new or modify environment variable
 * @info: Structure
 * @tokens: tokens
 *  Return: 2
 */
int _setenv(info_t *info, char **tokens)
{
	int i;

	if (!tokens[1] || !tokens[2])
	{
		printf("Incorrect number of arguements\n");
		return (2);
	}
	else
	{
		for (i = 0; environ[i]; i++)
			if (environ[i][0] == tokens[1][0] && environ[i][1] ==
			 tokens[1][1] && environ[i][2] == tokens[1][2])
			{
				strcpy(environ[i], tokens[2]);
				return (2);
			}
	}
	info->condition = 2;
	return (2);
}

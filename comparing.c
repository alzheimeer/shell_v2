#include "hsh.h"

/**
 * comparing - compare function.
 * @info: structur
 * @tokens: The tokenized line.
 * Description: This function compare the built-in with the command entered.
 * Return: The built-in function result.
 */
int comparing(info_t *info, char **tokens)
{
	if (tokens[0] == NULL)
		return (1);
	if (_strcmp(tokens[0], "exit") == 0)
	{
		exit(1);
		return (0);
	}
	if (_strcmp(tokens[0], "setenv") == 0)
		return (_setenv(info, tokens));
	if (_strcmp(tokens[0], "unsetenv") == 0)
		return (_unsetenv(info, tokens));
	if (_strcmp(tokens[0], "cd") == 0)
		return (_cd(info, info->tokens));
	return (1);
}

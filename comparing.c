#include "hsh.h"

/**
 * comparing - compare function.
 * @tokens: The tokenized line.
 * Description: This function compare the built-in with the command entered.
 * Return: The built-in function result.
 */
int comparing(char **tokens)
{
	if (tokens[0] == NULL)
		return (1);
	if (_strcmp(tokens[0], "exit") == 0)
		return (0);
	if (_strcmp(tokens[0], "env") == 0)
		_env(tokens);
	if (_strcmp(tokens[0], "cd") == 0)
		return (_cd(tokens));
	return (1);
}

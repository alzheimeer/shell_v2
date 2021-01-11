#include "hsh.h"

/**
 * _cd - explore function.
 * @info: structur
 * @tokens: The number of arguments for cd.
 * Return: 2.
 */
int _cd(info_t *info, char **tokens)
{
	if (tokens[1] == NULL)
		chdir("/");
	else
	{
		if (chdir(tokens[1]) != 0)
			print_error(info, "can't cd to ");
	}
	return (2);
}
/**
 * _env - prints the enviroment varibles.
 * @commands: commands
 * Return: none
**/
void _env(char **commands)
{
	int i;
	char *s = *environ;

	if (commands[1] != NULL)
		return;

	for (i = 0; s; i++)
	{
		write(STDIN_FILENO, s, _strlen(s));
		write(STDIN_FILENO, "\n", 1);
		s = *(environ + i);
	}
}

#include "hsh.h"

/**
 * _cd - explore function.
 * @args: The number of arguments for cd.
 * Return: 2.
 */
int _cd(char **args)
{
	if (args[1] == NULL)
		chdir("/");
	else
	{
		if (chdir(args[1]) != 0)
			errors(args);
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

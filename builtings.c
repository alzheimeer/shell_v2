#include "hsh.h"
/**
 * _cd - explore function.
 * @info: structur
 * @tokens: The number of arguments for cd.
 * Return: 2.
 */
int _cd(info_t *info, char **tokens)
{
	char *s, buffer[1024], buffer2[1024], *o, *pathstr, str[80];
	int i;

	o = getcwd(buffer, 1024);
	if (tokens[1] == NULL)
		for (i = 0; environ[i]; i++)
			if (environ[i][0] == 'H' && environ[i][1] == 'O' && environ[i][2] == 'M')
			{
				pathstr = environ[i];
				pathstr = &pathstr[5];
				chdir(pathstr);
			}
	else if (tokens[1][0] == '-')
		for (i = 0; environ[i]; i++)
			if (environ[i][0] == 'O' && environ[i][1] == 'L' && environ[i][2] == 'D')
			{
				pathstr = environ[i];
				pathstr = &pathstr[7];
				chdir(pathstr);
				s = getcwd(buffer, 1024);
				printf("%s\n", s);
			}
	else
		if (chdir(tokens[1]) != 0)
			print_error(info, "can't cd to ");
	s = getcwd(buffer2, 1024);
	for (i = 0; environ[i]; i++)
		if (environ[i][0] == 'P' && environ[i][1] == 'W' && environ[i][2] == 'D')
		{
			sprintf(str, "PWD=%s", s);
			strcpy(environ[i], str);
		}
	for (i = 0; environ[i]; i++)
		if (environ[i][0] == 'O' && environ[i][1] == 'L' && environ[i][2] == 'D')
		{
			sprintf(str, "OLDPWD=%s", o);
			strcpy(environ[i], str);
		}
	return (2);
}

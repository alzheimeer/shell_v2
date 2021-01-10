#include "hsh.h"

/**
 * identifydelim - identify the delimiters
 * @info: the parameter struct
 * @line: line read the stdin or file
 * Return: none
 */
void identifydelim(info_t *info, char *line)
{
	int j = 0;
	int i;

	_memset(info->flaqs, '0', 20);
	for (i = 0; line[i]; i++)
	{
		if (line[i] == '|' && line[i + 1] == '|' && line[i + 2] == ' ' &&
		 line[i - 1] == ' ')
			info->flaqs[j] = CMD_OR, j++;
		if (line[i] == '&' && line[i + 1] == '&' && line[i + 2] == ' ' &&
		 line[i - 1] == ' ')
			info->flaqs[j] = CMD_AND, j++;
		if (line[i] == '|' && line[i + 1] == ' ' && line[i - 1] == ' ')
			info->flaqs[j] = CMD_PIPE, j++;
		if (line[i] == ';' && line[i + 1] == ' ' && line[i - 1] == ' ')
			info->flaqs[j] = SEMICOLON, j++;
	}
	info->numberflaqs = j;
}

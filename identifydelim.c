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
		if (line[i] == '|' && line[i + 1] == '|')
		{
			info->flaqs[j] = CMD_OR, j++;
		}
		else if (line[i] == '|')
			info->flaqs[j] = CMD_PIPE, j++;
		if (line[i] == '&' && line[i + 1] == '&')
			info->flaqs[j] = CMD_AND, j++;
		if (line[i] == ';')
			info->flaqs[j] = SEMICOLON, j++;
	}
	info->numberflaqs = j;
}

/**
 * identifydelim2 - identify the delimiters
 * @info: the parameter struct
 * @line: line read the stdin or file
 * Return: none
 */
void identifydelim2(info_t *info, char *line)
{
	int i, y = 0;

	for (i = 0; line[i]; i++)
	{
		if (line[i] == '>' && line[i + 1] == '>')
			info->ident = REOUTDOBLE;
		else if (line[i] == '>' && info->ident != REOUTDOBLE)
			info->ident = REOUT;
		else if (line[i] == '<' && line[i + 1] == '<')
			info->ident = REINDOBLE;
		else if (line[i] == '<' && info->ident != REINDOBLE)
			info->ident = REIN;
		else if (line[i] == '#')
			info->identcomment = COMMENT, y = 1;
		if (y == 1)
			line[i] = ' ';
	}
}

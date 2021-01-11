#include "hsh.h"

/**
 * checkone - test delimeter
 * @info: the parameter struct
 * @lines: commands
 * Return: none
 */
void checkone(info_t *info, char **lines)
{
	int j, i;

	i = _strtoken(lines);
	for (j = 0; j < i; j++)
	{
		identifydelim2(info, lines[j]), info->tokens = cuttingspace(lines[j]);
		info->argv = info->tokens, info->condition = comparing(info, info->tokens);
		if (info->tokens[0] && info->condition == 1)
		{
			redireccion(info), find_cmd(info);
			if (j >= 1 && info->flaqs[j - 1] == CMD_OR && info->status)
				executing(info);
			if (j >= 1 && info->flaqs[j - 1] == CMD_AND && !info->status)
				executing(info);
			if (j >= 1 && info->flaqs[j - 1] == SEMICOLON)
				executing(info);
			if ((info->flaqs[j] == CMD_PIPE) ||
				info->write_inPipe == 1)
			{
				if (!info->pipefd[READ] && !info->pipefd[WRITE])
				{
					if (pipe(info->pipefd) == -1)
						exit(1);
					info->write_inPipe = 1;
				}
				else
					info->write_inPipe = 0;
				executing(info);
				info->read_inPipe = 1;
				if (info->write_inPipe == 0)
				{
					info->read_inPipe = 0, info->write_inPipe = 0;
					info->pipefd[READ] = 0, info->pipefd[WRITE] = 0;
				}
			}
			else if (j == 0 && info->flaqs[j] != CMD_PIPE)
				executing(info);
		}
		free(info->tokens);
	}
}

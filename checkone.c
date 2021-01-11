#include "hsh.h"

/**
 * checkone - test delimeter
 * @info: the parameter struct
 * @lines: commands
 * @condition: flaq for stop main loop
 * Return: condition
 */
int checkone(info_t *info, char **lines, int condition)
{
	int j, i;

	for (i = 0; lines[i]; i++)
	{}
	for (j = 0; j < i; j++)
	{
		identifydelim2(info, lines[j]),	info->tokens = cuttingspace(lines[j]);
		condition = comparing(info, info->tokens), redireccion(info);
		info->argv = info->tokens, find_cmd(info);
		if (j >= 1 && info->flaqs[j - 1] == CMD_OR && condition == 1 && info->status)
			executing(info);
		if (j >= 1 && info->flaqs[j - 1] == CMD_AND && condition == 1 &&
		 !info->status)
			executing(info);
		if (j >= 1 && info->flaqs[j - 1] == SEMICOLON && condition == 1)
			executing(info);
		if ((info->flaqs[j] == CMD_PIPE && condition == 1) ||
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
		else if (j == 0 && condition == 1 && info->flaqs[j] != CMD_PIPE)
			executing(info);
		free(info->tokens);
	}
	return (condition);
}

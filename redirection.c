#include "hsh.h"

/**
 * redireccion - locate sings of redirection and #
 * @info: structur
 * Return: none
 */
void redireccion(info_t *info)
{
	int i = 0;

	for (i = 1; info->tokens[i]; i++)
	{
		if (info->tokens[i][0] == '>' && info->tokens[i][1] == '>')
		{
			info->filename = info->tokens[i + 1];
			info->redirfilefd = open(info->filename, O_CREAT | O_WRONLY | O_APPEND);
			dup2(info->redirfilefd, STDOUT_FILENO), close(info->redirfilefd);
			info->tokens[i] = NULL, info->tokens[i + 1] = NULL;
		}
		else if (info->tokens[i][0] == '>')
		{
			info->filename = info->tokens[i + 1];
			info->redirfilefd = open(info->filename, O_CREAT | O_WRONLY | O_TRUNC);
			dup2(info->redirfilefd, STDOUT_FILENO), close(info->redirfilefd);
			info->tokens[i] = NULL, info->tokens[i + 1] = NULL;
		}
		else if (info->tokens[i][0] == '<' && info->tokens[i][1] == '<')
		{
			info->filename = info->tokens[i + 1];
			info->tokens[i] = NULL, info->tokens[i + 1] = NULL;
		}
		else if (info->tokens[i][0] == '<')
		{
			info->filename = info->tokens[i + 1];
			info->redirfilefd2 = open(info->filename, O_RDWR);
			dup2(info->redirfilefd2, STDIN_FILENO);
			info->tokens[i] = NULL, info->tokens[i + 1] = NULL;
		}
		else if (info->tokens[i][0] == '#')
			info->tokens[i] = NULL, info->tokens[i + 1] = NULL;
	}
}

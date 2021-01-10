#include "hsh.h"

/**
 * redireccion - locate sings of redirection and #
 * @info: structur
 * Return: none
 */
void redireccion(info_t *info)
{
	int i = 0;

	info->dup_stdin = dup(STDIN_FILENO), info->dup_stdout = dup(STDOUT_FILENO);
	for (i = 1; info->tokens[i]; i++)
	{
		if (info->tokens[i][0] == '>' && info->tokens[i][1] == '>')
		{
			info->filename = info->tokens[i + 1];
			info->redirfilefd = open(info->filename, O_CREAT |
			 O_WRONLY | O_APPEND, 0666);
			dup2(info->redirfilefd, STDOUT_FILENO), close(info->redirfilefd);
			info->tokens[i] = NULL, info->tokens[i + 1] = NULL;
		}
		else if (info->tokens[i][0] == '>')
		{
			info->filename = info->tokens[i + 1];
			info->redirfilefd = open(info->filename, O_CREAT |
			 O_WRONLY | O_TRUNC, 0666);
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

/**
 * restore_in_out - restores stdin/out after redirect
 * @info: the parameter struct
 */
void restore_in_out(info_t *info)
{
	if (info->dup_stdin)
	{
		dup2(info->dup_stdin, STDIN_FILENO);
		close(info->dup_stdin);
		info->dup_stdin = 0;
	}
	if (info->dup_stdout)
	{
		dup2(info->dup_stdout, STDOUT_FILENO);
		close(info->dup_stdout);
		info->dup_stdout = 0;
	}
}


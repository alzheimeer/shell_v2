#include "hsh.h"

/**
 * redireccion - locate sings of redirection and #
 * @info: structur
 * Return: none
 */
void redireccion(info_t *info)
{
	int j;

	info->dup_stdin = dup(STDIN_FILENO), info->dup_stdout = dup(STDOUT_FILENO);
	j = _strtoken(info->tokens);
	if (info->ident == REOUTDOBLE || info->ident == REOUT || info->ident == REIN)
	{
		info->filename = info->tokens[j - 1];
		info->tokens[j - 1] = NULL;
	}
	if (info->ident == REOUTDOBLE)
	{
		info->redirfilefd = open(info->filename, O_CREAT |
		 O_WRONLY | O_APPEND, 0666);
		dup2(info->redirfilefd, STDOUT_FILENO), close(info->redirfilefd);
	}
	else if (info->ident == REOUT)
	{
		info->redirfilefd = open(info->filename, O_CREAT |
		 O_WRONLY | O_TRUNC, 0666);
		dup2(info->redirfilefd, STDOUT_FILENO), close(info->redirfilefd);
	}
	else if (info->ident == REINDOBLE)
	{
		printf("no se para que es esto");
	}
	else if (info->ident == REIN)
	{
		info->redirfilefd2 = open(info->filename, O_RDWR);
		dup2(info->redirfilefd2, STDIN_FILENO);
	}
}

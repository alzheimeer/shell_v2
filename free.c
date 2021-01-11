#include "hsh.h"

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
	info->ident = 0, info->identcomment = 0;
}
/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
	if (all)
	{
		if (info->readfd > 2)
			close(info->readfd);
		__getline(-1);
		_putchar(BUF_FLUSH);
	}
}

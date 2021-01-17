#include "hsh.h"

/**
 * executing - execute function.
 * @info: structur
 * Return: none
 */
void executing(info_t *info)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return;
	}
	if (pid == 0)
	{
		if (info->read_inPipe == 1)
		{
			dup2(info->pipefd[READ], STDIN_FILENO);
			close(info->pipefd[READ]);
		}
		if (info->write_inPipe == 1)
		{
			close(info->pipefd[READ]); /* cerrar extremo no necesario */
			dup2(info->pipefd[WRITE], STDOUT_FILENO);
			close(info->pipefd[WRITE]);
		}
		if (execve(info->path, info->tokens, environ) == -1)
		{
			print_error(info, "not found");
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		if (info->read_inPipe == 1)
			close(info->pipefd[READ]); /* extremo no necesario ya */

		if (info->write_inPipe == 1)
			close(info->pipefd[WRITE]); /* extremo no necesario ya */
	}
	do {
		waitpid(pid, &(info->status), WUNTRACED);
	} while (!WIFEXITED((info->status)) && !WIFSIGNALED((info->status)));
}

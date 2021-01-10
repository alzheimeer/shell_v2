#include "hsh.h"
/**
 * main - start to play
 * @ac: argc count.
 * @av: argv array.
 * Return: status code
 */
int main(int ac, char **av)
{
	char *line = NULL;
	char **lines = NULL;
	info_t info[] = {INFO_INIT};
	int condition = 1, flaqread = 0;

	if (ac == 2)
	{
		info->readfd = open_file(info, av[1], 0);
		if (info->readfd == -1)
			free_info(info, 1), exit(info->err_num);
		else
			flaqread = 1;
	}
	signal(SIGINT, sigint_handler);
	while (condition)
	{
		if (flaqread == 1)
		{
			line = __getline(info->readfd);
			if (!line)
				break;
		}
		else
		{
			write(STDIN_FILENO, "$ ", 2);
			line = reading();
		}
		identifydelim(info, line);
		lines = cutting(line);
		condition = checkone(info, lines, condition);
		free(line);
		free(lines);
	}
	return (EXIT_SUCCESS);
}

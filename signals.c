#include "hsh.h"

/**
 * sigint_handler -  Signal Handler for SIGINT
 * When Ctrl+C is pressed, SIGINT signal is generated,
 * we can catch this signal and run our defined signal handler.
 * @sigint: Reset handler to catch SIGINT next time.
 * Return: 0
 */

void sigint_handler(int sigint)
{
	(void)sigint;

	signal(SIGINT, sigint_handler);
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}

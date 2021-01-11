#include "hsh.h"
/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: none
 */
void print_error(info_t *info, char *estr)
{
	info->count++;
	if (!info->argv[1])
		printf("%s: %d: %s: %s\n"
		, info->fname, info->count, info->argv[0], estr);
	else
		printf("%s: %d: %s: %s: %s\n"
		, info->fname, info->count, info->argv[0],
	    estr, info->argv[1]);
}

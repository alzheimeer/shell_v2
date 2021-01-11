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
	printf("%s: %d: %s: %s", info->fname, info->count, info->argv[0], estr);
}

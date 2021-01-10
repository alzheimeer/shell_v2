#include "hsh.h"

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

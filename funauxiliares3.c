#include "hsh.h"

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
		_eputchar(str[i]), i++;
}
/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
		write(2, buf, i), i = 0;
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * _memcpy - copies bytes from src to dest
 * @dest: pointer to destination buffer
 * @src: pointer to source buffer
 * @n: number of bytes to copy
 * Return: pointer to destination buffer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	while (n--)
		*(dest + n) = *(src + n);
	return (dest);
}

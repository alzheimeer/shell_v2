#include "hsh.h"
/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcmp - Compare function.
 * @s1: The pointer to the first string.
 * @s2: The pointer to the second string.
 * Description: This function compare two strings.
 * Return: Indication number.
 */
int _strcmp(char *s1, char *s2)
{
	char c1, c2;

	do {
		c1 = *s1++;
		c2 = *s2++;

		if (c1 == '\0')
			return (c1 - c2);
	} while (c1 == c2);

	return (c1 - c2);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * *_strcat - main function.
 * @src: The source.
 * @dest: The destination.
 * Description: This function concatenates two strings.
 * Return: The pointer to destination buffer.
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int r = 0;

	while (dest[i])
		i++;

	while (src[r])
	{
		dest[i] = src[r];
		i++;
		r++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * *_strcpy - main function.
 * @src: The source.
 * @dest: The destination.
 * Description: This function copies the string pointed to by src,
 * including the terminating null byte (\0), to the buffer pointed to by dest.
 * Return: The pointer to dest.
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

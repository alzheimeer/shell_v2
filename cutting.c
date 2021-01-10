#include "hsh.h"

/**
 * cutting - cut delimiters
 * @line: line to cut
 * Return: Null-terminated array de tokens.
 */
char **cutting(char *line)
{
	char *slice;
	char **tokens;
	int position = 0;
	int buffer = 2048;
	int oldbuffer;

	tokens = malloc(buffer * sizeof(char *));
	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	slice = strtok(line, "&|#;");
	while (slice != NULL)
	{
		tokens[position] = slice;
		position++;
		if (position >= buffer)
		{
			oldbuffer = buffer;
			buffer += 2048;
			tokens = _realloc(tokens, oldbuffer, buffer);
			if (!tokens)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		slice = strtok(NULL, "&|#;");
	}
	tokens[position] = NULL;
	return (tokens);
}
/**
 * cuttingspace - cut space
 * @line: line to cut
 * Return: Null-terminated array de tokens.
 */
char **cuttingspace(char *line)
{
	char *slice;
	char **tokens;
	int position = 0;
	int buffer = 2048;
	int oldbuffer;

	tokens = malloc(buffer * sizeof(char *));
	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	slice = strtok(line, " \t\n\r");
	while (slice != NULL)
	{
		tokens[position] = slice;
		position++;
		if (position >= buffer)
		{
			oldbuffer = buffer;
			buffer += 2048;
			tokens = _realloc(tokens, oldbuffer, buffer);
			if (!tokens)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		slice = strtok(NULL, " \t\n\r");
	}
	tokens[position] = NULL;
	return (tokens);
}

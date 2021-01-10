#include "hsh.h"

/**
 * find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL, *pathstr;
	int i;

	for (i = 0; environ[i]; i++)
		if (environ[i][0] == 'P' && environ[i][1] == 'A' && environ[i][2] == 'T')
			pathstr = environ[i];

	info->path = info->argv[0];

	path = find_path(info, pathstr, info->argv[0]);
	if (path)
		info->path = path;
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

/**
 * starts_with - checks if haystack starts with needle
 * @string: string to search
 * @findstr: the substring to find
 * Return: address of next char of string or NULL
 */
char *starts_with(const char *string, const char *findstr)
{
	while (*findstr)
		if (*findstr++ != *string++)
			return (NULL);
	return ((char *)string);
}

/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
		return (1);
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

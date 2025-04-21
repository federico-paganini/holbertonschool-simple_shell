#include "shell.h"

/**
 * interpreter - Identifies correct executable path for a command.
 *
 * @argv: Array of args from command line.
 * @args: Arsed command args.
 * @env: Environ to free in exit built-in case.
 *
 * Return: Dynamically allocated string containing the exec path or NULL
 */
char *interpreter(char **argv, char **args, char **env)
{
	char *cmd;
	char *path;

	if (args[0] == NULL)
		return (NULL);

	if (builtin_handler(argv, args, env))
		return (NULL);

	cmd = args[0];
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			return (strdup(cmd));
		}
		else
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], cmd);
			return (NULL);
		}
	}
	path = find_path(cmd);
	if (path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: command not found\n", argv[0], cmd);
		return (NULL);
	}

	return (path);
}

/**
 * find_path - searches for a command in system PATH directories
 * @cmd: command name to search
 * Return: dynamically allocated string with full executable path or NULL
 */
char *find_path(char *cmd)
{
	char *path = getenv("PATH");
	char **paths = tokenize_path(path);
	char *full_path = NULL;
	int len, i = 0;

	if (paths == NULL)
		return (NULL);

	while (paths[i])
	{
		len = strlen(paths[i]) + strlen(cmd) + 2;
		full_path = malloc(len);

		if (full_path == NULL)
		{
			free_vector(paths);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", paths[i], cmd);

		if (access(full_path, X_OK) == 0)
		{
			free_vector(paths);
			return (full_path);
		}

		free(full_path);
		i++;
	}

	free_vector(paths);

	return (NULL);
}

/**
 * tokenize_path - splits PATH variable into array of directory paths
 * @path: string containing path environment variables
 * Return: dynamically allocated array of dir paths or NULL
 */
char **tokenize_path(char *path)
{
	char **pathvector;
	int paths = 1;
	int len = 0, start = 0;
	int j = 0, i = 0, k;

	for (k = 0; path[k]; k++)
	{
		if (path[k] == ':')
			paths++;
	}
	pathvector = malloc(sizeof(char *) * (paths + 1));
	if (pathvector == NULL)
		return (NULL);
	while (path[i] != '\0')
	{
		start = i;
		while (path[i] != ':' && path[i] != '\0')
			i++;
		len = i - start;
		if (len == 0)
		{
			pathvector[j++] = strdup(".");
		}
		else
		{
			pathvector[j] = malloc(sizeof(char) * (len + 1));
			if (pathvector[j] == NULL)
			{
				free_vector(pathvector);
				return (NULL);
			}
			memcpy(pathvector[j], path + start, len);
			pathvector[j++][len] = '\0';
		}
		if (path[i] == '\0')
			break;
		i++;
	}
	pathvector[j] = NULL;
	return (pathvector);
}

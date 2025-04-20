#include "shell.h"

char *interpreter(char **args, char **env)
{
	char *cmd;
	char *path;

	if (args == NULL || args[0] == NULL)
		return (NULL);

	cmd = args[0];
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			return (cmd);
		}
		else
		{
			perror(cmd);
			return (NULL);
		}
	}
	path = find_path(cmd, env);
	if (path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return (NULL);
	}

	return (path);
}

char *find_path(char *cmd, char **env)
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

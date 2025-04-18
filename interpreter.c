#include "shell.h"

char *interpreter(char **args, char **env)
{
	char *cmd = args[0];
	char *path;
	
	if (args == NULL || cmd == NULL)
		return (NULL);

	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			return(cmd);
		}
		else
		{
			perror(cmd);
			return(NULL);
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
	char **orgpath;
	char *result;
	char *full_path = NULL;

	while (result != NULL)
	{
		result = strstr(aux, cmd);

		if (result != NULL)
			result += strlen(cmd);

		if (*result == ':' || *result == '\0')
			break;

		aux = result;
	}



#include "shell.h"

/**
 * copy_envp - creates copy of the envp variable array
 * @env: array of environment variables to copy
 * Return: dynamically allocated array containing a copy of envp variables
 */
char **copy_envp(char **env)
{
	int i, count = 0;
	char **new_env;

	while (env[count] != NULL)
		count++;

	new_env = malloc((count + 1) * sizeof(char *));
	if (new_env == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < count; i++)
	{
		new_env[i] = strdup(env[i]);
		if (new_env[i] == NULL)
		{
			perror("strdup");
			free_vector(new_env);
			exit(EXIT_FAILURE);
		}
	}
	new_env[count] = NULL;

	return (new_env);
}

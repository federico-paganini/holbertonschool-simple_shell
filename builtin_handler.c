#include "shell.h"

/**
 * builtin_handler -
 *
 * @argv:
 * @args:
 * @env:
 *
 * Return:
 */

int builtin_handler(char **argv, char **args, char **env)
{
	exit_builtin(argv, args, env);

	if (env_builtin(args, env))
		return (1);

	return (0);
}

/**
 * exit_builtin -
 *
 * @argv:
 * @args:
 * @env:
 */

void exit_builtin(char **argv, char **args, char **env)
{
	int exit_code = 0;

	if (strcmp(args[0], "exit") != 0)
		return;

	if (args[1])
	{
		if (valid_exit_status(args[1]))
		{
			exit_code = atoi(args[1]);
		}
		else
		{
			fprintf(stderr, "%s: exit: %s: numeric argument required\n",
					argv[0], args[1]);

			exit_code = 2;
		}
	}

	write(1, "logout\n", 8);
	free_vector(args);
	free_vector(env);
	exit(exit_code);
}

/**
 * env_builtin -
 *
 * @argv:
 * @args:
 * @env:
 *
 * Return:
 */

int env_builtin(char **args, char **env)
{
	int i = 0;

	if (strcmp(args[0], "env") != 0)
		return (0);

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}

	return (1);
}



#include "shell.h"

/**
 * main - Entry function of shell.
 *
 * @argc:
 * @argv:
 * @env:
 *
 * Return: 0.
 */

int main(int argc __attribute__((__unused__)),
		char **argv, char **envp)
{
	char **args; 
	char **env = copy_envp(envp);
	char *path;

	for (;;)
	{
		args = get_args(get_line(env));
		path = interpreter(argv, args, env);

		if (path == NULL)
		{
			free_vector(args);
			continue;
		}

		execute(path, args, env);

		free_vector(args);
		free(path);
	}
	free_vector(env);

	return (EXIT_SUCCESS);
}

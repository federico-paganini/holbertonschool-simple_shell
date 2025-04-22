#include "shell.h"

/**
 * main - Entry function of shell.
 *
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * @envp: Enviorment variables passed to the program
 *
 * Return: 0.
 */

int main(int argc __attribute__((__unused__)),
		char **argv, char **envp)
{
	char **args;
	char **env = copy_envp(envp);
	char *path;
	int last_status;

	setup_signal();

	for (;;)
	{
		args = get_args(get_line(env));

		if (args == NULL)
			continue;

		path = interpreter(argv, args, env, &last_status);

		if (path == NULL)
		{
			free_vector(args);
			continue;
		}

		last_status = execute(path, args, env);
	}
	free_vector(env);

	return (last_status);
}

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

int main(int argc __attribute__((__unused__)), char **argv, char **envp)
{
	char **args, /***env = copy_env(envp)*/;
	char *path;

	for (;;)
	{
		args = check_validity(get_line(), argv);

		if (args == NULL)
		{
			free_all(args);
			continue;
		}

		/*path = interpreter(args, envp);*/
		/*execute(path, &args[1], env);*/
		free_all(args);
	}
	return (EXIT_SUCCESS);
}

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

int main(int argc __attribute__((__unused__)), char **argv __attribute__((__unused__)), char **envp)
{
	char **args /***env = copy_env(envp)*/;
	char *path;

	for (;;)
	{
		args = check_validity(get_line());

		if (args == NULL)
		{
			free_all(args);
			continue;
		}

		/*path = interpreter(args, envp);*/
		/*execute(path, &args[1], env);*/
	}
	return (EXIT_SUCCESS);
}

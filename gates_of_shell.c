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
		char **argv __attribute__((__unused__)), char **envp)
{
	char **args = check_validity(get_line()), 
	char **env = copy_envp(envp);
	char *path;

	for (;;)
	{
		args = check_validity(get_line());

		if (args == NULL)
			continue;

		path = interpreter(args, env);

		if (path == NULL)
		{
			free_all(args);
			continue;
		}
		
		free_all(args);
	}
	return (EXIT_SUCCESS);
}

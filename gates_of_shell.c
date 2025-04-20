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
	char **args; 
	char **env = copy_envp(envp);
	char *path;

	for (;;)
	{
		args = get_args(get_line());

		if(args == NULL)
			continue;

		path = interpreter(args, env);

		if (path == NULL)
		{
			free_vector(args);
			continue;
		}

		printf("Path: %s\n", path);
		
		free_vector(args);
		free_vector(env);
		free(path);
	}

	return (EXIT_SUCCESS);
}

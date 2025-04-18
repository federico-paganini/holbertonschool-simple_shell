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
	char **args;

	for (;;)
	{
		args = check_validity(get_line());

		if (args == NULL)
		{
			continue;
		}

		free_all(args);
	}
	return (EXIT_SUCCESS);
}

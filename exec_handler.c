#include "shell.h"

/**
 * execute -
 *
 * @cmd:
 * @args:
 * @env:
 */
void execute(char *cmd, char **args, char **env)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(cmd, args, env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	else
	{
		perror("fork");
	}
}

#include "shell.h"

/**
 * execute - creates child process to execute a command
 *
 * @cmd: path to the executable command
 * @args: array of args to pass to the command
 * @env: array of environment variables
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

	free_vector(args);
	free(cmd);
}

#include "shell.h"

/**
 * execute - creates child process to execute a command
 *
 * @cmd: path to the executable command
 * @args: array of args to pass to the command
 * @env: array of environment variables
 * Return: The status exit of execute task.
 */
int execute(char *cmd, char **args, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(cmd, args, env) == -1)
		{
			perror("execve");
			free_vector(args);
			free_vector(env);
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if(WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	else
	{
		perror("fork");
	}

	free_vector(args);
	free(cmd);
	return (status);
}

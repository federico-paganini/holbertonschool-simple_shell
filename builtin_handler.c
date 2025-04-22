#include "shell.h"

/**
 * builtin_handler - processses builtin shell commands
 *
 * @argv: the array containing the program and args, used for error messages
 * @args:the tokenized command args
 * @env: environment variables array
 * @status: current status (ignored)
 *
 * Return: 1 if a builtin command was executed 0 otherwise
 */

int builtin_handler(char **argv, char **args, char **env, int status)
{
	exit_builtin(argv, args, env, status);

	if (env_builtin(args, env))
		return (1);

	return (0);
}

/**
 * exit_builtin - executes exit builtin command
 *
 * @argv: the array containing program name and args
 * @args: tokenized array of command args
 * @env: array of env variables to be freed
 * @status: status code (ignored)
 */

void exit_builtin(char **argv, char **args, char **env, int status)
{
<<<<<<< HEAD
	(void)argv;
	(void)status;
=======
	int exit_code = status;
>>>>>>> f5a6ea7c257ec69289377020af986eb9db247317

	if(strcmp(args[0], "exit") != 0)
		return;

	if(isatty(STDIN_FILENO))
		write(1, "logout\n", 7);

	free_vector(args);
	free_vector(env);

	exit(EXIT_SUCCESS);
}

/**
 * env_builtin - executes environment builtin command
 *
 * @args: the tokenized command args
 * @env: array of environment variables
 *
 * Return: 1 id the env command was executed
 */

int env_builtin(char **args, char **env)
{
	int i = 0;

	if (strcmp(args[0], "env") != 0)
		return (0);

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}

	return (1);
}

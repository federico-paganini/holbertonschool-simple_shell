#include "shell.h"

/**
 * args_count - Counts number of words in a line.
 * @line: Input string to analyze.
 * Return: Number of arguments in the string.
 */
int args_count(char *line)
{
	int i = 0;
	int count = 0;

	while (line[i] != '\0')
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;

		if (line[i] != '\0')
		{
			count++;
			while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
				i++;
		}
	}
	return (count);
}

/**
 * _wlen - Computes length of a word in a string.
 * @line: Input string containing words separated by spaces or tabs.
 * Return: Length of the first word in the string.
 */
int _wlen(char *line)
{
	int i = 0;

	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		i++;
	return (i);
}

/**
 * free_vector - Frees a dynamically allocated array of strings.
 * @args: Array to free
 * Return: Void (frees memory to prevent leaks).
 */
void free_vector(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/**
 * copy_envp - Creates copy of the envp variable array.
 * @env: Array of environment variables to copy.
 * Return: Dynamically allocated array containing a copy of envp variables.
 */
char **copy_envp(char **env)
{
	int i, count = 0;
	char **new_env;

	while (env[count] != NULL)
		count++;

	new_env = malloc((count + 1) * sizeof(char *));
	if (new_env == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < count; i++)
	{
		new_env[i] = strdup(env[i]);
		if (new_env[i] == NULL)
		{
			perror("strdup");
			free_vector(new_env);
			exit(EXIT_FAILURE);
		}
	}
	new_env[count] = NULL;

	return (new_env);
}

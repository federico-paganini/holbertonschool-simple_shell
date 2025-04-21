#include "shell.h"

/**
 * get_line - Handles the imput and the interactive mode.
 * @env: Enviorment variable array
 * Return: A pointer to the memory adress of the line.
 */
char *get_line(char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
		write(1, "#cisfun$ ", 9);

	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		if (errno == EINTR)
		{
			clearerr(stdin);
			return (NULL);
		}

		if (interactive)
			write(1, "\nlogout\n", 8);

		free(line);
		free_vector(env);
		exit(EXIT_SUCCESS);
	}

	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}

/**
 * get_args - tokenizes an input line to arguments
 * @line: input string containing commands
 * Return: dynamically allocated array of args or NULL
 */
char **get_args(char *line)
{
	char **args;
	int i = 0;

	if (line == NULL)
		return (NULL);

	while (line[i] == ' ' || line[i] == '\t')
		i++;

	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}

	args = tokenize_line(&line[i]);

	if (args == NULL)
		return (NULL);

	free(line);
	return (args);
}

/**
 * tokenize_line - splits line into tokens
 * @line: input string to tokenize
 * Return: dinamically allocated array of tokens or NULL
 */
char **tokenize_line(char *line)
{
	char **args = malloc(sizeof(char *) * (args_count(line) + 1));
	int i = 0, j;
	int word = 0;

	if (args == NULL)
		return (NULL);

	while (line[i] != '\0')
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;

		if (line[i] == '\0')
			break;

		args[word] = malloc(sizeof(char) * (_wlen(&line[i]) + 1));
		if (args[word] == NULL)
		{
			free_vector(args);
			return (NULL);
		}

		j = 0;
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
			args[word][j++] = line[i++];

		args[word++][j] = '\0';
	}
	args[word] = NULL;

	return (args);
}

/**
 * handle_sigint -
 *
 * @sig:
 */

void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

/**
 * setup_signal -
 */

void setup_signal(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGINT, &sa, NULL);
}

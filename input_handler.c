#include "shell.h"

/**
 * get_line - Handles the imput and the interactive mode.
 *
 * return: A pointer to the memory adress of the line.
 */

char *get_line(void)
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
		if (interactive)
			write(1, "logout\n", 7);
		free(line);
		exit(EXIT_SUCCESS);
	}

	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}

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

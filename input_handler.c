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
	ssize_t nread;
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
		write(1, "#cisfun$ ", 9);
		fflush(stdout);
	}

	nread = getline(&line, &len, stdin);

	if ((strcmp(line, "exit\n") == 0) || nread = -1)
	{
		if (interactive)
		{
			write(1, "logout\n", 7);
			fflush(stdout);
		}
		free(line);
		exit(EXIT_SUCCESS);
	}

	if (nread > 0 && line[nread-1] == '\n')
		line[nread - 1] = '\0';

	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}

	return (line);
}

char **check_validity(char *line)
{

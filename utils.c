#include "shell.h"

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

int _wlen(char *line)
{
	int i = 0;

	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		i++;
	return (i);
}

void free_all(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

#include "shell.h"

int arg_count(const char *line)
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

int _wlen(const char *line)
{
	int i = 0;

	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		i++;
	return (i);
}

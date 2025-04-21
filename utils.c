#include "shell.h"

/**
 * args_count - counts number of words in a line
 * @line: input string to analyse
 * Return: number of arguments in the string
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
 * _wlen - computes length of a word in a string
 * @line: input string containing words separated by spaces or tabs
 * Return: length of the first word in the string
 */
int _wlen(char *line)
{
	int i = 0;

	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		i++;
	return (i);
}

/**
 * free_vector - frees a dynamically allocated array of strings
 * @args: array to free
 * Return: void (frees memory to prevent leaks)
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

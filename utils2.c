#include "shell.h"

/* _atoi - Converts a string to integer.
 *
 * @s: String to convert.
 *
 * Return: The first int finded (0 if there's no int).
 */

int _atoi(char *s)
{
	int i = 0, n = 0, value = 0, isnum = 0;
	unsigned int absn = 0;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			value++;
		i++;
	}

	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			absn = absn * 10 + (s[i] - '0');
			isnum = 1;

			if (s[i + 1] == '\0' || s[i + 1] < '0' || s[i + 1] > '9')
			{
				break;
			}
		}
		i++;
	}

	value = (value % 2 == 0) ? 0 : -1;
	n = (value == 0) ? absn : absn * value;
	return (isnum ? n : isnum);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: First string to compare.
 * @s2: Second string to compare.
 *
 * Return: Returns te comparison result.
 */

int _strcmp(char *s1, char *s2)
{

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}

		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strdup - Duplicates a string.
 *
 * @str: String to duplicate.
 *
 * Return: The memory adress of the string.
 */

char *_strdup(char *str)
{
	char *dup;
	int i = 0;
	int count = strlen(str);

	dup = malloc(sizeof(char) * (count +1));

	if (dup == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}

	dup[i] = '\0';

	return (dup);
}

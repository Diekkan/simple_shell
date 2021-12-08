#include "libshell.h"
/**
 *read_input - read input function used to read the input.
 *Return: input.
 */
char *read_input(void)
{
	int chars;
	char *buffer = NULL;
	size_t i = 0;

	chars = getline(&buffer, &i, stdin);

	if (chars == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(buffer);
		return (NULL);
	}

	if (chars > 1)
		buffer[_strlen(buffer) - 1] = '\0';

	return (buffer);
}

/**
 * _strcmp - string compare
 *@s1: string to be compared
 *@s2: string 2
 *
 * Return: difference between ascii or 0
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i];)
	{
		if (s1[i] != s2[i])
			break;

		i++;
	}

	if ((s1[i] > s2[i]) || (s1[i] < s2[i]))
		return (s1[i] - s2[i]);

	return (0);
}


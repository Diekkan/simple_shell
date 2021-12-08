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

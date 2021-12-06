#include "libshell.h"
/**
 *read_input - read input function used to read the input.
 *Return: input.
 */
char *read_input(void)
{
	char *buffer;
	size_t size = 1024;
	int chars;

	buffer = malloc(size * sizeof(char));
	if (buffer == NULL)
		return (NULL);

	chars = getline(&buffer, &size, stdin);

	if (chars == 1)
		return (NULL);
	if (chars == -1)
		exit(1);
	
	buffer[_strlen(buffer) - 1] = '\0';
	
	return (buffer);
}

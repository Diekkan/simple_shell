#include "libshell.h"
/**
 *read_input - read input function used to read the input.
 *Return: input.
 */
char *read_input(void)
{
	char *buffer;
	size_t size = 1024;

	buffer = malloc(size * sizeof(char));
	if (buffer == NULL)
		return (NULL);
 	getline(&buffer, &size, stdin);
	
	/** if (buffer[0] != 0)
	{
		printf("Escribiste: %s\n", buffer);
		printf("Pude leer: %lu caracter(es)\n", characters);
		putchar(10); 
	}
	else
	{
		return (NULL);
	} */

	return (buffer);
}

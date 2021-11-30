#include "libshell.h"

char* read_input(void)
{
	char *buffer;
	size_t size = 1024;
        size_t characters;

        buffer = malloc(size * sizeof(char));
	if (buffer == NULL)
		return (NULL);

	characters = getline(&buffer, &size, stdin);
	if (buffer[0] != 0)
	{
		printf("Escribiste: %s\n", buffer);
		printf("Pude leer: %lu caracter(es)\n", characters);
		putchar(10);
	}

	return (buffer);
}

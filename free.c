#include "libshell.h"

/**
 * free_array - frees an array of strings
 *@strings: string array
 *@size: size of array
 */
void free_array(char **strings, int size)
{
	int i;
	char *token;

	for (i = 0; i < size; i++)
	{
		token = strings[i];
		free(token);
	}
	free(strings);
}


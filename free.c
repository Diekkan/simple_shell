#include "libshell.h"

/**
 * free_array - frees an array of strings
 *@strings: string array
 *@size: size of array allocated.
 */
void free_array(char **strings, int size)
{
	int i;

	for(i = 0; i <= size; i++)
	{
		free(strings[i]);
	}
	free(strings);
}

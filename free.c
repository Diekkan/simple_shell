#include "libshell.h"

/**
 * free_array - frees an array of strings
 *@strings: string array
 *@size: size of array allocated.
 */
void free_array(char **strings)
{
	int i;

	for(i = 0; strings[i] != NULL; i++)
	{
		free(strings[i]);
	}
	free(strings);
}

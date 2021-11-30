#include "libshell.h"

/**
 * tokenizer - tokenizes the input received.
 *@buffer: string received from input.
 *Return: returns an array of strings.
 */

char** tokenizer(char *buffer)
{
	int i = 0;
	char **tokenized;
	char *token;

	token = strtok(buffer, " ");
	tokenized = malloc(sizeof(char *) * 1024);

	while(token)
	{
		tokenized[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	return (tokenized);
}

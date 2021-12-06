#include "libshell.h"

/**
 * tokenizer - tokenizes the input received.
 *@buffer: string received from input.
 *Return: returns an array of strings.
 */

char **tokenizer(char *buffer, char *separator)
{
	int i = 0;
	char **tokenized;
	char *token;
	size_t size = 1024;

	token = strtok(buffer, separator);
	tokenized = malloc(sizeof(char *) * size);

	while (token)
	{
		tokenized[i] = token;
		token = strtok(NULL, separator);
		i++;
	}

	tokenized[i] = NULL;
	return (tokenized);
}

/**
 * free_list -a function that frees a list_t list.
 *@head: first node.
 */
void free_list(path_d *head)
{
	path_d *current = head, *next;

	while (current)
	{
		next = current->next;
		free(current->directory);
		free(current);
		current = next;
	}

	head = NULL;
}

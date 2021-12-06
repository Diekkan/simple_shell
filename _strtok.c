#include "libshell.h"
/**
 * _strtok - makes the tokens.
 * @string: recibe string to be tokenized.
 * @separator: add a separator.
 * Return: token.
 */
char *_strtok(char *string, char separator)
{
	unsigned int i;
	char *token;

	token = malloc(sizeof(char) * strlen(string) + 1);
	if (token == NULL)
		return (NULL);

	for (i = 0; string[i] != separator; i++)
	{
		string[i] = token[i];
	}
	string[i] = '\0';

	return (token);
}

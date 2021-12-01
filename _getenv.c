#include "libshell.h"
#include <stdio.h>
char *_getenv(const char *name);
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */

char *_getenv(const char *name)
{
	char **envtoken;
	char *targetenv;
	unsigned int i;
	int match;

	for(i = 0; environ[i] != NULL; i++)
	{
		match = strncmp(environ[i], name, strlen(name));
		if (match == 0)
			break;
	}

	if(match != 0)
		return (NULL);
	envtoken = malloc(sizeof(char *) * 2);
	envtoken[0] = strtok(environ[i], "=");
	envtoken[1] = strtok(NULL, "=");

	targetenv = envtoken[1];

	return (targetenv);
}

/**
 *
 * 
 *
 */

char *tokenize_path(void);
{
	char *path = _getenv("PATH");
	char **pathdirs;

	pathdirs
	tokenizer(path, ":");

	
}



#include "libshell.h"
#include <stdio.h>

char *_getenv(const char *name);
char **tokenize_path(void);
path_d *token_to_list(char **tokens);
path_d *add_node(path_d **head, char *str);

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
/* int main(void)
{
	char **tokenized;
	unsigned int i;
	tokenized = malloc(sizeof(char *) * 1024);
	tokenized = tokenize_path();

	for(i = 0; tokenized[i] != NULL; i++)
		printf("%s\n", tokenized[i]);
	token_to_list(tokenized);
	return (0);
}*/
/**
 *
 *
 *
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
	if (envtoken == NULL)
		return (NULL);
	
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

char **tokenize_path(void)
{
	char *path = _getenv("PATH");
	char **pathdirs;

	pathdirs = malloc(sizeof(char *) * 6);
	if (pathdirs == NULL)
		return (NULL);

	pathdirs = tokenizer(path, ":");
	return(pathdirs);
}

/**
 *
 *
 */
path_d *token_to_list(char **tokens)
{
	unsigned int i;
	path_d *fNode;

	fNode = NULL;
	for(i = 0; tokens[i] != NULL; i++)
	{
		fNode = add_node(&fNode, tokens[i]);
	}

	return (fNode);
}
/**
 *
 */

path_d *add_node(path_d **head, char *str)
{
	path_d *nNode, *lNode;

	if (!(head && str))
		return (NULL);

	nNode = malloc(sizeof(path_d));
	if (!nNode)
		return (NULL);

	nNode->directory = str;
	printf("%s\n", nNode->directory);
	if (!nNode->directory)
	{
		free(nNode);
		return (NULL);
	}
	nNode->next = NULL;

	if (!*head)
	{
		*head = nNode;
		return (nNode);
	}

	lNode = *head;
	while (lNode->next)
	{
		lNode = lNode->next;
	}
	lNode->next = nNode;
	return (nNode);
}

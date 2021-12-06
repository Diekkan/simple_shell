#include "libshell.h"

/**
 *_getenv - function that gets the enviroment.
 *@name: name of the variable.
 *Return:the value of the variable.
 */
char *_getenv(const char *name)
{
	char **envtoken;
	char *targetenv;
	unsigned int i;
	int match;

	for (i = 0; environ[i] != NULL; i++)
	{
		match = strncmp(environ[i], name, strlen(name));
		if (match == 0)
			break;
	}

	if (match != 0)
		return (NULL);

	envtoken = tokenizer(environ[i], "=");

	targetenv = envtoken[1];
	return (targetenv);
}
/**
 * tokenize_path - makes token out of a variable path.
 * Return: token directory.
 *
 */

char **tokenize_path(void)
{
	char *path = _getenv("PATH");
	char **pathdirs;

	pathdirs = tokenizer(path, ":");
	return (pathdirs);
}

/**
 * pathtoken_to_list - makes a linked list of directories.
 * @tokens: recibes directories.
 * Return: a pointer to the start of the list.
 */
path_d *pathtokens_to_list(char **tokens)
{
	unsigned int i;
	path_d *fNode;

	fNode = NULL;
	i = 0;

	fNode = add_node(&fNode, tokens[i]);
	i++;
	while (tokens[i])
	{
		add_node_pathend(&fNode, tokens[i]);
		i++;
	}

	free_array(tokens, 1024);
	return (fNode);
}
/**
 * add_node - adds a node in the begining.
 * @head: memory address where is saved.
 * @str: string recibed in the node.
 * Return: a pointer to the list.
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
/**
 * add_node - adds a node in the begining.
 * @head: memory address where is saved.
 * @str: string recibed in the node.
 * Return: a pointer to the list.
 */
path_d *add_node_pathend(path_d **head, char *str)
{
	path_d *nNode;
	path_d *lNode;

	if (!(head && str))
	return (NULL);

	nNode = malloc(sizeof(path_d));
	if (!nNode)
	return (NULL);

	nNode->directory = str;

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

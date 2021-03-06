#include "libshell.h"

/**
 *_getenv - function that gets the enviroment.
 *@name: name of the variable.
 *Return:the value of the variable.
 */
char *_getenv(char *name)
{
	char *targetenv = NULL;
	int comparison;
	unsigned int i;


	for (i = 0; environ[i] != NULL; i++)
	{
		comparison = strncmp(environ[i], name, 4);
		if (comparison == 0)
			break;
	}

	if (comparison != 0)
		return (NULL);

	strtok(environ[i], "=");

	targetenv = strtok(NULL, "=");
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
 * Return: a pointer to the start of the list.
 */
path_d *pathtokens_to_list(void)
{
	unsigned int i;
	char **tokens = tokenize_path();
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

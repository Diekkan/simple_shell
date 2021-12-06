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

	token = strtok(buffer, separator);
	tokenized = malloc(sizeof(char *) * 1024);

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
 *
 */

tok *inputtoken_to_list(char **tokenin)
{
        unsigned int i;
        tok *fNode;

        fNode = NULL;

	i = 0;

	fNode = add_node_tokens(&fNode, tokenin[i]);
	i++;
        while (tokenin[i])
        {
                add_node_end(&fNode, tokenin[i]);
		i++;
        }

        return (fNode);

}
/**
 * add_node_end - adds a new node at the end of a list_t list.
 *@head: first node.
 *@str: string to be duplicated.
 *Return: address of the new node.
 */
tok *add_node_end(tok **head, char *str)
{
	tok *nNode;
	tok *lNode;

	if (!(head && str))
		return (NULL);

	nNode = malloc(sizeof(tok));
	if (!nNode)
		return (NULL);

	nNode->token = str;
	/* printf("%s\n", nNode->token); */
	if (!nNode->token)
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

tok *add_node_tokens(tok **head, char *str)
{
	tok *nNode, *lNode;

	if (!(head && str))
		return (NULL);

	nNode = malloc(sizeof(tok));
	if (!nNode)
		return (NULL);

	nNode->token = str;
	/* printf("%s\n", nNode->token);*/
	if (!nNode->token)
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

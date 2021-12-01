#include "libshell.h"

/**
 * main - our shell main function.
 *
 *
 * Return: void.
 */

int main(void)
{
	char *input;
	char **tokens;
	int i;
	int id, status;

	do {
		shell_prompt();
		input = read_input();
		tokens = tokenizer(input, " ");

		for (i = 0; tokens[i] != NULL; i++)
			printf("%s\n", tokens[i]);

		id = fork();

		if (id == 0)
		{
		}
		else
		{
			wait(&status);
		}
	} while (1);
}

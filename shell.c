#include "libshell.h"
#define UNUSED(x) (void)(x)
/**
 * main - our shell main function.
 *
 *
 * Return: void.
 */

int main(int ac, char **av, char **env)
{
	char *input;
	char **tokens;
	int i;

	UNUSED(ac);
	UNUSED(av);
	UNUSED(env);

	while (1)
	{
		shell_prompt();
		input = read_input();
		input[strlen(input) - 1] = '\0';

		tokens = tokenizer(input, " ");

		for (i = 0; tokens[i] != NULL; i++)
			printf("Token:%s. No.:%d\n", tokens[i], i);

		run_exec(tokens);
	}
}

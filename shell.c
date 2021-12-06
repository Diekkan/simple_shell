#include "libshell.h"
#define UNUSED(x) (void)(x)
/**
 * main - our shell main function.
 * @ac: variable counter.
 * @av: variable vector.
 * @env: variable envairoment.
 * Return: 0.
 */

int main(int ac, char **av, char **env)
{
	char *input;
	char **tokens, **pathtokens;
	path_d *pathdirs;
	int builtin;

	UNUSED(ac);
	UNUSED(av);
	UNUSED(env);

	pathtokens = tokenize_path();
	pathdirs = pathtokens_to_list(pathtokens);

	while (1)
	{
		input = NULL;
		shell_prompt();
		input = read_input();
		if (input == NULL)
			continue;

		input[strlen(input) - 1] = '\0';
		tokens = tokenizer(input, " ");
		builtin = verify_builtin(tokens);
		if (builtin == 1)
			break;
		exec_identifier(pathdirs, tokens);

	}

	free_list(pathdirs);
	return (0);

}

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
	int builtin, isaty = 1;

	UNUSED(ac);
	UNUSED(av);
	UNUSED(env);

	pathtokens = tokenize_path();
	pathdirs = pathtokens_to_list(pathtokens);

	while (isaty == 1)
	{
		isaty = isatty(STDIN_FILENO);
		if (isaty == 1)
		{
			write(STDOUT_FILENO, "$>", 2);
		}
		else
		{
			isaty = 0;
		}
		input = read_input();
		if (input == NULL)
			continue;
		tokens = tokenizer(input, " ");
		builtin = verify_builtin(tokens);
			if (builtin == 1)
				break;
		exec_identifier(pathdirs, tokens);
		free(input);
	}
	return (0);

}

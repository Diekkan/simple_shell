#include "libshell.h"
#define UNUSED(x) (void)(x)

/**
 * main - our shell main function.
 * Return: 0.
 */

int main(void)
{
	char *input;
	char **tokens;
	path_d *pathdirs;

	pathdirs = pathtokens_to_list();

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$>", 2);
		input = read_input();
		if (input == NULL || _strncmp(input, "exit", 4) == 0)
			break;
		if (_strncmp(input, "\n", 1) == 0 ||
		_strncmp(input, "env", 3) == 0)
		{
			if (_strncmp(input, "env", 3) == 0)
				env_builtin();

			continue;
		}
		tokens = tokenizer(input, " ");
		exec_identifier(pathdirs, tokens);
	}

	return (0);

}

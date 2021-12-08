#include "libshell.h"
#define UNUSED(x) (void)(x)

/**
 * main - our shell main function.
 * Return: 0.
 */

int main(void)
{
	char *input, *path;
	char **tokens;
	char **pathtokens;

	path = _getenv("PATH");
	pathtokens = tokenizer(path, ":");
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$>", 2);
		input = read_input();
		if (input == NULL || _strncmp(input, "exit", 4) == 0)
		{
			free(input);
			break;
		}
		if (_strncmp(input, "\n", 1) == 0 ||
		_strncmp(input, "env", 3) == 0)
		{
			if (_strncmp(input, "env", 3) == 0)
				env_builtin();

			free(input);
			continue;
		}
		tokens = tokenizer(input, " ");
		is_exec(pathtokens, tokens);

		free(input);
		free(tokens);
	}

	free(pathtokens);
	return (0);
}

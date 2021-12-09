#include "libshell.h"

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
		if (input == NULL || _strcmp(input, "exit") == 0)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(input);
			break;
		}
		if (_strcmp(input, "\n") == 0 ||
		_strcmp(input, "env") == 0)
		{
			if (_strcmp(input, "env") == 0)
				env_builtin();
			free(input);
			continue;
		}
		tokens = tokenizer(input, " ");
		if (tokens == NULL)
		{
			free(input);
			continue;
		}
		is_exec(pathtokens, tokens);
		free(input);
		free(tokens);
	}
	free(pathtokens);
	return (0);
}

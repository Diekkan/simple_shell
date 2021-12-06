#include "libshell.h"

int detect_builtin(char **tokens)
{
	char *exit = strdup(exit, "exit");
	char *env = strdup(env, "env");
	int match;

	match = _strncmp(tokens[0], exit, strlen(exit));
	if (match == 0)
	{
		exit_shell();
		return (0);
	}

	match = _strncmp(tokens[0], env, strlen(env));
	if (match == 0)
	{
		print_env();
		return (0);
	}

	return (-1);
}

int ()

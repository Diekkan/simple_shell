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
	char **tokens, **pathtokens;
	tok *tokenlist;
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
		if(input == NULL)
			continue;
		
		input[strlen(input) - 1] = '\0';
		tokens = tokenizer(input, " ");
		builtin = verify_builtin(tokens);
		if(builtin == 1)
			break;
		/*i = 0;
		while (pathtokens[i])
		{
			printf("%s\n", pathtokens[i]);
			i++;
		}
		pathprint = pathdirs;
		while (pathprint)
                {
                        printf("%s\n", pathprint->directory);
			pathprint = pathprint->next;
		} */
		tokenlist = inputtoken_to_list(tokens);

		while (tokenlist)
		{
			printf("%s\n", tokenlist->token);
			tokenlist = tokenlist->next;
		}
		exec_identifier(pathdirs, tokens);	
		 /*run_exec(tokenlist);*/
	}

	return (0);
}

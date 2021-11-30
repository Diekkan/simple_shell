#include "libshell.h"

/**
 * main - our shell main function.
 *
 */

int main(void)
{
	char *input;
	int id, status;

	do
	{
		shell_prompt();
		input = read_input();
		tokenizer(input);
		id = fork();
		
		if (id == 0)
		{
		}
		else
		{
			wait(&status);
		}
	}while (1);
}

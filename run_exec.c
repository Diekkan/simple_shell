#include "libshell.h"

int run_exec(char **token)
{
	int child_pid = fork();
	int status;

	if (child_pid == 0)
	{	
		if ((execve(token[0], token, NULL)) == -1)
			perror("Error");
	}

	wait(&status);
	return (0);
}

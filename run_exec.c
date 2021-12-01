#include "libshell.h"

int run_exec(char **token)
{
	int child_pid = fork();
	int status, err;

	if (child_pid == 0)
	{	
		err = execve(token[0], token, NULL);
		if (err == -1)
			perror("Error");
	}

	wait(&status);
	return (0);
}

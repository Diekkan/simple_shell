#include "main.h"
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"/bin/ls ", "-l", "/tmp", NULL};
	int child_id, status, exec;

	child_id = fork();

	if (child_id == 0)
	{
		exec = execve(argv[0], argv, NULL);
		if (exec == -1)
			perror("Error");
	}

	wait(&status);
	return (0);
}

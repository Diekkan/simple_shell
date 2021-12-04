#include "libshell.h"

int exec_identifier(path_d *pathlist, char **tokens)
{
	char *command = tokens[0];
       	char *possibledir;
	path_d *directory = pathlist;
	int isdir, isdir2, findfile;
	struct stat st;

	isdir = strncmp(command, "/", 1);
	isdir2 = strncmp(command, ".", 1);

	if (isdir == 0 || isdir2 == 0)
	{
		run_exec(command, tokens);
		return (0);
	}
	printf("aca esta\n");

	while(directory)
	{
		possibledir = strdup(directory->directory);
		possibledir = strcat(possibledir, "/");
		possibledir = strcat(possibledir, command);
		printf("%s\n", possibledir);
		findfile = stat(possibledir, &st);
		if (findfile == 0)
		{
			run_exec(possibledir, tokens);
			break;
		}
		directory = directory->next;
	}
	return (0);
}

int run_exec(char *pathname, char **tokens)
{
	int child_pid = fork();
	int status, err;

	if (child_pid == 0)
	{
		err = execve(pathname, tokens , NULL);
		if (err == -1)
			perror("Error");
	}

	wait(&status);
	return (0);
}

#include "libshell.h"
/**
 *
 *
 */
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

	while(directory)
	{
		possibledir = strdup(directory->directory);
		possibledir = strcat(possibledir, "/");
		possibledir = strcat(possibledir, command);
		/* printf("%s\n", possibledir);*/
		findfile = stat(possibledir, &st);
		if (findfile == 0)
		{
			run_exec(possibledir, tokens);
			break;
		}
		directory = directory->next;
	}
	if (findfile != 0)
		perror("Error");
	return (0);
}

/**
 *
 *
 *
 */
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
/**
 *
 *
 *
 */

int verify_builtin(char **tokens)
{
	int exit, env;

	exit = _strncmp(tokens[0], "exit", 4);

	if(exit == 0)
	{
		return (1);
	}

	env = _strncmp(tokens[0], "env", 3);

	if(env == 0)
	{
		env_builtin();
		return (0);
	}

	return (-1);
}
/**
 *
 *
 */

void env_builtin(void)
{
	int i;

	for(i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}


#include "libshell.h"
/**
 *exec_identifier - look for a identifier if found the identifier executes.
 *@pathlist:path variables
 *@tokens:input token.
 *Return: 0.
 */
int exec_identifier(path_d *pathlist, char **tokens)
{
	char *command = tokens[0];
	char *possibledir;
	path_d *directory = pathlist;
	int isdir, isdir2, findfile;
	struct stat st;

	isdir = _strncmp(command, "/", 1);
	isdir2 = _strncmp(command, ".", 1);

	if (isdir == 0 || isdir2 == 0)
	{
		run_exec(command, tokens);
		return (0);
	}

	while (directory)
	{
		possibledir = _strdup(directory->directory);
		possibledir = _strncat(possibledir, "/", 1);
		possibledir = _strncat(possibledir, command, strlen(command));
		findfile = stat(possibledir, &st);
		if (findfile == 0)
		{
			run_exec(possibledir, tokens);
			free(possibledir);
			break;
		}
		directory = directory->next;
	}
	if (findfile != 0)
	{
		free(possibledir);
		perror("Error");
	}
	return (0);
}

/**
 *run_exec - run the executer.
 *@pathname: name of the path.
 *@tokens: tokens value.
 *Return: 0.
 */
int run_exec(char *pathname, char **tokens)
{
	int child_pid = fork();
	int status, err;

	if (child_pid == 0)
	{
		err = execve(pathname, tokens, NULL);
		if (err == -1)
			perror(tokens[0]);
	}

	wait(&status);
	return (0);
}

/**
 *env_builtin - print enviroment.
 */

void env_builtin(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 *is_exec - look for a identifier if found the identifier executes.
 *@path:path variables
 *@tokens:input token.
 *Return: 0.
 */
int is_exec(char **path, char **tokens)
{
	char *command = tokens[0];
	char *possibledir;
	int isdir, isdir2, findfile, i = 0;
	struct stat st;

	isdir = _strncmp(command, "/", 1);
	isdir2 = _strncmp(command, ".", 1);

	if (isdir == 0 || isdir2 == 0)
	{
		run_exec(command, tokens);
		return (0);
	}

	while (path[i])
	{
		possibledir = _strdup(path[i]);
		possibledir = _strncat(possibledir, "/", 1);
		possibledir = _strncat(possibledir, command, strlen(command));
		findfile = stat(possibledir, &st);
		if (findfile == 0)
		{
			run_exec(possibledir, tokens);
			free(possibledir);
			break;
		}
		free(possibledir);
		i++;
	}
	if (findfile != 0)
	{
		perror(tokens[0]);
		return (-1);
	}
	return (0);
}

/**
 * _strncpy - a function that copies a string.
 * @src: source string
 * @dest: dest string
 * @n: number of chars copied.
 *
 * Return: string dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

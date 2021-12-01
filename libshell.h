#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

struct path_dirs
{
	char *directory;
	path_d *next;
} path_d;

extern char **environ;

void shell_prompt(void);
char *read_input(void);
char **tokenizer(char *buffer, char *separator);
int _strcmp(char *s1, char *s2);
int run_exec(char **token);

#endif

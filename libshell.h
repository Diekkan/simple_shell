#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

typedef struct path_d
{
	char *directory;
	struct path_d *next;
} path_d;

extern char **environ;

/** shell-made functions */
void shell_prompt(void);
char *read_input(void);
char **tokenizer(char *buffer, char *separator);
char *_getenv(const char *name);
char **tokenize_path(void);
char *find_exec();
path_d **token_to_list(char **tokens);
int run_exec(char **token);

/** useful functions */
char *_getenv(const char *name);
int _strncmp(char *s1, char *s2);
int _strlen(char *str);
path_d *add_node(path_d **head, char *str);

#endif

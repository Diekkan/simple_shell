#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
/**
 * struct path_d - pathlist
 *@directory: string with dir
 *@next: pointer to next node
 */
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
char **tokenize_path(void);
char *find_exec();
path_d *pathtokens_to_list(void);
int exec_identifier(path_d *pathlist, char **tokens);
int run_exec(char *pathname, char **tokens);
void env_builtin(void);
int verify_builtin(char **tokens);
void exit_builtin(void);
int is_exec(char **path, char **tokens);

/** useful functions */
char *_getenv(char *name);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *str);
path_d *add_node(path_d **head, char *str);
path_d *add_node_pathend(path_d **head, char *str);
char *_strdup(char *str);
char *_strncat(char *dest, char *src, int n);
void free_list(path_d *head);
void free_array(char **strings, int size);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
int _strcmp(char *s1, char *s2);

#endif

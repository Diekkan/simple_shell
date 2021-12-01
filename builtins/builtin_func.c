#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

/*here we declaretes the commands*/
/*puse estas tres porque es probable que las pidan en algun advance*/
/*exit es obligatoria*/

int func_cd(char **args);
int func_help(char **args);
int func_exit(char **args);

/* listamos los comandos en un string */
/* probar con struct si da el tiempo*/

char *str_builtin_func[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&func_cd,
	&func_help,
	&func_exit
};

int num_builtins(void)
{
	return (sizeof(str_builtin_func) / sizeof(char *));
}

/*implementanding*/

int func_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "function expected argument to \"cd\"n");
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("func");
	}
	return (1);
}

int func_help(char **args)
{
	int i;

	printf("add info to show");

	for (i = 0; i < num_builtins(); i++)
	{
		printf(" %s\n", str_builtin_func[i]);
	}
	printf("use the manual or google it\n");
	return (1);

}

int func_exit(char **args)
{
	return (0);
}

/** add to our excute function*/
int lsh_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return lsh_launch(args);
}

	}

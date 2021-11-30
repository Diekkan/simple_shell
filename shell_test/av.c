#include "main.h"
#define UNUSED(x) (void)(x)

/**
 * main - av.
 *@ac: arguments count.
 *@av: arguments value.
 *
 *Return: always 0.
 */

int main(int ac, char **av)
{
	UNUSED(ac);
	int i;

	for (i = 1; av[i] != NULL;)
	{
		printf("%s\n", av[i]);
		i++;
	}
	
	return (0);
}

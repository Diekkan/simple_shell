#include "main.h"

/**
 *
 *
 */
extern char** environ;

void main(void)
{
	int i;

	for(i = 0; environ[i] != 0; i++)
		printf("%s", environ[i]);
}

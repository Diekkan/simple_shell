#include "main.h"

int main(void)
{
	char *buffer;
	size_t size = 1024;
	size_t characters;
	int mypid = getpid();
	int myppid = getppid();

	buffer = malloc(size * sizeof(char));
	
	while (buffer)
	{
		printf("$la-mejor-shell# ");
		characters = getline(&buffer, &size, stdin);
		if (buffer[0] != 0)
		{	
			printf("Escribiste: %s\n", buffer);
			printf("Pude leer: %lu caracter(es)\n", characters);
			printf("PID: %d y PPID: %d\n", mypid, myppid);
			putchar(10);
		}
	}
	return (0);
}

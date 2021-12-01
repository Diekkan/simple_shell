#include "libshell.h"

/**
 * _strcmp - string compare
 *@s1: string to be compared
 *@s2: string 2
 *
 * Return: difference between ascii or 0
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	int i;

	for (i = 0; (s1[i]) && (i <= n);)
	{
		if (s1[i] != s2[i])
			break;

		i++;
	}

	if ((s1[i] > s2[i]) || (s1[i] < s2[i]))
		return (s1[i] - s2[i]);

	return (0);
}

#include "libshell.h"

/**
 * _strncmp - string compare
 *@s1: string to be compared
 *@s2: string 2
 *@n: number variable.
 * Return: difference between ascii or 0
 */

int _strncmp(char *s1, char *s2, int n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
}

/**
 * _strncat - a function that concatenates two strings
 * @dest: dest string
 * @src: source string
 * @n: n of bytes.
 * Return: dest string modified
 */

char *_strncat(char *dest, char *src, int n)
{
	int chs1;
	int chs2;

	for (chs1 = 0; dest[chs1] != '\0';)
	{
		chs1++;
	}

	for (chs2 = 0; chs2 < n && src[chs2] != '\0';)
	{
		dest[chs1] = src[chs2];
		chs2++;
		chs1++;
	}

	dest[chs1] = '\0';

	return (dest);
}

/**
 * _strdup - copies the string given as parameter.
 *@str: string to be duplicated
 *Return: a pointer to the duplicated string.
 */

char *_strdup(char *str)
{
	char *p;
	unsigned int i, len;

	i = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	p = malloc(sizeof(char) * (len + 1024));

	if (p == NULL)
		return (NULL);

	while ((p[i] = str[i]) != '\0')
	{
		i++;
	}
	return (p);
}
/**
 * _strlen - a function that returns the lenght of a string.
 * @s: string.
 * Return: 0 success.
 */

int _strlen(char *s)
{
	int string = 0;

	while (*(s + string) != 0)
	{
		string++;
	}

	return (string);
}

/**
 * _strstr - a function that locates a substring.
 *@haystack: base string.
 *@needle: substring to be located in haystack.
 * Return: a pointer to the beginning, NULL if not located.
 */

char *_strstr(char *haystack, char *needle)
{
	char *res;
	char *aux;

	while (*haystack != '\0')
	{
		res = haystack;
		aux = needle;

		while (*aux == *haystack && *aux != '\0'
		       && *haystack != '\0')
		{
			haystack++;
			aux++;
		}
		if (*aux == '\0')
			return (res);
		haystack = res + 1;
	}
	return (NULL);
}

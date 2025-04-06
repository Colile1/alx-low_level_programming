#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: string to search
 * @c: character to locate
 *
 * Return: pointer to the first occurrence of c, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return ((void *)0);
}

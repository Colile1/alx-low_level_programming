#include "main.h"
/**
 * _strncpy - Copies at most n bytes from src to dest.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to copy from src.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	/* Copyin at most n bytes from src to dest */
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	/* Filling the remaining space with null bytes if necessary */
	for ( ; i < n; i++)
		dest[i] = '\0';

	return dest;
}
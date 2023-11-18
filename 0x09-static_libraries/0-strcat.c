#include "main.h"

/**
 * _strcat - Concatenate two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to the resulting string `dest`
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int src_len = 0;

	/* Calculate the length of the destination string */
	while (dest[dest_len] != '\0')
		dest_len++;

	/* Copy the source string to the destination string */
	while (src[src_len] != '\0')
	{
		dest[dest_len] = src[src_len];
		dest_len++;
		src_len++;
	}

	dest[dest_len] = '\0'; /* Add the null terminator */

	return (dest);
}

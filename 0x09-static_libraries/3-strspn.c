#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to search
 * @accept: The string containing the characters to match
 *
 * Return: The number of bytes in the initial segment of s which
 * consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int match = 1;
	unsigned int i, j;

	for (i = 0; s[i] != '\0' && match; i++)
	{
		match = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				match = 1;
				break;
			}
		}
	}
	return (count);
}

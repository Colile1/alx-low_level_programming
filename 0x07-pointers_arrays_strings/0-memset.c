#include "main.h"

/**
 * _memset - Fills memory with a constant byte
 * @s: The pointer to the memory area
 * @b: The constant byte to fill the memory
 * @n: The number of bytes to fill
 *
 * Return: A pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}

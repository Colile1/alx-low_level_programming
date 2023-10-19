#include "main.h"
/**
 * rot13 - Encodes a string using ROT13.
 * @str: The string to encode.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		char c = str[i];

		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			if ((c > 'M' && c <= 'Z') || (c > 'm' && c <= 'z'))
				str[i] -= 13;
			else
				str[i] += 13;
		}
		i++;
	}

	return (str);
}

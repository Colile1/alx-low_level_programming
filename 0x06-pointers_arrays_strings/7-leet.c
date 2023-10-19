#include "main.h"
/**
 * leet - Encodes a string into 1337.
 * @str: The string to encode.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *str)
{
	int i = 0;
	char *letters = "aAeEoOtTlL";
	char *leet = "4433007711";

	while (str[i] != '\0')
	{
		int j = 0;

		while (letters[j] != '\0')
		{
			if (str[i] == letters[j])
				str[i] = leet[j];
			j++;
		}
		i++;
	}

	return (str);
}

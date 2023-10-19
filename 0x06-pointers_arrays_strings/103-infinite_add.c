#include "main.h"
#include <stdio.h>

/**
 * infinite_add - Adds two numbers.
 * @n1: The first number as a string.
 * @n2: The second number as a string.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer.
 *
 * Return: A pointer to the result, or 0 if the result cannot be stored.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, carry, sum;

	i = j = k = carry = 0;
	while (n1[i] != '\0' || n2[j] != '\0')
	{
		int digit1 = (n1[i] != '\0') ? (n1[i] - '0') : 0;
		int digit2 = (n2[j] != '\0') ? (n2[j] - '0') : 0;

		sum = digit1 + digit2 + carry;
		carry = sum / 10;
		if (k + 1 >= size_r)
			return (0);
		r[k] = (sum % 10) + '0';
		i++;
		j++;
		k++;
	}

	if (carry > 0 && k + 1 < size_r)
	{
		r[k] = carry + '0';
		k++;
	}

	if (k >= size_r)
		return (0);

	r[k] = '\0';

	return (r);
}

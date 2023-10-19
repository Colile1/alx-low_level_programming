#include "main.h"

/**
 * infinite_add - Adds two numbers stored as strings.
 * @n1: The first number as a string.
 * @n2: The second number as a string.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer.
 *
 * Return: A pointer to the result, or 0 if the result can't be stored in r.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, carry, sum;
	int i, j, k;

	/* Calculate the lengths of n1 and n2 */
	for (len1 = 0; n1[len1]; len1++)
		;
	for (len2 = 0; n2[len2]; len2++)
		;

	if (size_r <= len1 + len2 + 1) /* Check if result can be stored */
		return (0);

	carry = 0;
	i = len1 - 1;
	j = len2 - 1;
	k = 0;
	while (i >= 0 || j >= 0 || carry)
	{
		int digit1 = (i >= 0) ? (n1[i] - '0') : 0;
		int digit2 = (j >= 0) ? (n2[j] - '0') : 0;

		sum = digit1 + digit2 + carry;
		carry = sum / 10;
		r[k] = (sum % 10) + '0';

		if (i >= 0)
			i--;
		if (j >= 0)
			j--;
		k++;
	}

	r[k] = '\0';

	/* Reverse the result */
	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		char temp = r[i];
		r[i] = r[j];
		r[j] = temp;
	}

	return r;
}

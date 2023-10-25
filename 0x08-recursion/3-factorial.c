#include "main.h"

/**
 * factorial - Returns the factorial of a number.
 * @n: The number for which to calculate the factorial.
 *
 * Return: The factorial of the number. If n is negative, returns -1.
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	if (n == 0)
	{
		return (1);
	}

	return (n * factorial(n - 1));
}

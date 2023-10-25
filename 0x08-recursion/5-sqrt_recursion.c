#include "main.h"

/**
 * calculate_sqrt - Calculates the natural square root recursively.
 * @n: The number for which to calculate the square root.
 * @guess: The current guess for the square root.
 *
 * Return: The natural square root of n, or -1 if it doesn't have one.
 */
int calculate_sqrt(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);
	return (calculate_sqrt(n, guess + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number for which to calculate the square root.
 *
 * Return: The natural square root of n, or -1 if it doesn't have one.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (calculate_sqrt(n, 0));
}

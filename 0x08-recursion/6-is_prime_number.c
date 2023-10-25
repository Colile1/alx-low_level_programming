#include "main.h"

/**
 * is_prime_number_recursive - checks if a number is prime recursively
 * @n: the number to check
 * @divisor: the current divisor to check
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_number_recursive(int n, int divisor)
{
	if (n <= 1)
		return (0);
	if (divisor <= 1)
		return (1);
	if (n % divisor == 0)
		return (0);
	return (is_prime_number_recursive(n, divisor - 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	return (is_prime_number_recursive(n, n - 1));
}

#include "main.h"

/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
    if (n <= 1)
        return (0);
    if (n == 2)
        return (1);
    if (n % 2 == 0)
        return (0);
    if (n <= 3)
        return (1);
    if (n % 3 == 0)
        return (0);
    if (n % 5 == 0)
        return (0);
    if (n % 7 == 0)
        return (0);
    if (n <= 31)
        return (1);
    if (n % 31 == 0)
        return (0);
    return (is_prime_number(n - 1));
}
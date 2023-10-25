#include "main.h"

/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to check.
 *
 * Return: 1 if prime, 0 if not.
 */
int is_prime_number(int n)
{
    if (n <= 1) // 0 and 1 are not prime numbers
        return 0;
    
    if (n <= 3) // 2 and 3 are prime numbers
        return 1;
    
    if (n % 2 == 0 || n % 3 == 0) // Divisible by 2 or 3
        return 0;
    
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }

    return 1;
}

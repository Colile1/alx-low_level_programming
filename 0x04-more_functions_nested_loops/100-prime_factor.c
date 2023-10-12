#include <stdio.h>
#include <math.h>

/**
 * largest_prime_factor - finds the largest prime factor of a number
 * @n: the number
 * Return: the largest prime factor
 */
long largest_prime_factor(long n)
{
    long largest = -1;

    while (n % 2 == 0)
    {
        largest = 2;
        n /= 2;
    }

    for (long i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            largest = i;
            n = n / i;
        }
    }

    if (n > 2)
        largest = n;

    return largest;
}

int main(void)
{
    long n = 612852475143;
    long result = largest_prime_factor(n);
    printf("%ld\n", result);
    return (0);
}

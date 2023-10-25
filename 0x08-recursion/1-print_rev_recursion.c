#include <stdio.h>

/**
 * _print_rev_recursion - prints a string in reverse using recursion
 *
 * @s: pointer to the string to print
 *
 * Return: Nothing.
 */
void _print_rev_recursion(char *s)
{
    if (*s != '\0')
    {
        _print_rev_recursion(s + 1);
        _putchar(*s);
    }
}

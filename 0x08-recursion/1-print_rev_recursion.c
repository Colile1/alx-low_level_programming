#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 * _print_rev_recursion - Prints a string in reverse.
 * @s: The string to be printed in reverse.
 * Return: null
 */
void _print_rev_recursion(char *s)
{
    if (*s)
    {
        _print_rev_recursion(s + 1);
        _putchar(*s);
    }
}

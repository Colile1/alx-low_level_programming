#include <stdio.h>
#include "main.h"

/**
 * _puts_recursion - Prints a string using recursion
 * @s: The string to be printed
 */
void _puts_recursion(char *s)
{
    if (*s == '\0')
    {
        _putchar('\n');  // Print a newline when we reach the end of the string
        return;
    }
    
    _putchar(*s);      // Print the current character
    _puts_recursion(s + 1);  // Recursively call the function with the next character
}

#include "main.h"

/**
* print_rev - prints a string in reverse followed by a new line
* @s: the string to print in reverse
*/
void print_rev(char *s)
{
    int length = 0;
    int i;

    /* Calculate string length */
    while (s[length] != '\0')
    {
        length++;
    }

    /* Print characters in reverse order */
    for (i = length - 1; i >= 0; i--)
    {
        _putchar(s[i]);
    }
    _putchar('\n');
}

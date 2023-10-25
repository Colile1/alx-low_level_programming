#include "main.h"

/**
 * is_palindrome - check if a string is a palindrome
 *
 * @s: input string
 *
 * Return: 1 if the string is a palindrome, 0 if not.
 */
int is_palindrome(char *s)
{
    int i, len;

    len = 0;
    while (s[len])
        len++;
    i = 0;
    while (i < len / 2)
    {
        if (s[i] != s[len - 1 - i])
            return (0);
        i++;
    }
    return (1);
}

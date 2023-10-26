#include "main.h"

/**
 * is_palindrome - check if a string is a palindrome
 *
 * @s: input string
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(char *s)
{
    int i, len;

    if (*s == '\0')
        return (1);

    len = 0;
    while (s[len] != '\0')
        len++;

    for (i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
            return (0);
    }

    return (1);
}
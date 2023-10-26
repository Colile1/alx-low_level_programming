#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * wildcmp - Compares two strings for wildcard matching.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: 1 if the strings are identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    
    if (*s2 == '*')
    {
        if (*(s2 + 1) == '\0')
            return (1);
        
        if (*s1 == '\0')
            return (0);
        
        return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
    }
    
    if (*s2 == '?' || *s1 == *s2)
    {
        if (*s1 == '\0' || *s2 == '\0')
            return (0);
        
        return (wildcmp(s1 + 1, s2 + 1));
    }
    
    return (0);
}
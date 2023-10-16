#include "main.h"
/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to a string.
 *
 * Description: This function takes a pointer to a string as a parameter
 * and returns the length of the string.
 */
int _strlen(char *s) /*strlen - Returns the length of a string*/
{
int len = 0;
while (s[len] != '\0')
{
len++;
}
return (len);
}

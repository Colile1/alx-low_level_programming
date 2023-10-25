#include <stdio.h>

/**
 * _puts_recursion - Prints a string followed by a new line.
 * @s: Pointer to the string to be printed.
 *
 * Description:
 * This function takes a pointer to a character array as its argument.
 * It uses recursion to print each character of the string one by one.
 * The base case of the recursion is when the null character is encountered,
 * indicating the end of the string. In this case, the function returns
 * without printing anything. Otherwise, the function prints the current
 * character using putchar(*s) and then recursively calls itself with the
 * next character in the string (s + 1). Finally, after the recursive calls
 * are complete, the function prints a new line character using putchar('\n').
 */
void _puts_recursion(char *s)
{
    if (*s == '\0')
        return;
    
    putchar(*s);
    _puts_recursion(s + 1);
    putchar('\n');
}
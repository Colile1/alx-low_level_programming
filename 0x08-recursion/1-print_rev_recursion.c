#include <stdio.h>

/**
 * print_string_reverse - Prints a string in reverse.
 * @s: Pointer to the string to be printed.
 *
 * Description:
 * This function takes a pointer to a character array as its argument.
 * It uses recursion to print each character of the string in reverse order.
 * The base case of the recursion is when the null character is encountered,
 * indicating the end of the string. In this case, the function returns
 * without printing anything. Otherwise, the function recursively calls
 * itself with the next character in the string (s + 1) and then prints
 * the current character using putchar(*s).
 */
void print_string_reverse(char *s)
{
    if (*s == '\0')
        return;
    
    print_string_reverse(s + 1);
    putchar(*s);
}
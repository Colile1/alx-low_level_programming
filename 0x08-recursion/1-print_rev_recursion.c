#include <stdio.h>

/**
 * _print_rev_recursion - Prints a string in reverse.
 * @s: Pointer to the string to be printed in reverse.
 *
 * Description:
 * This function takes a pointer to a character array as its argument and uses
 * recursion to print the string in reverse. The base case of the recursion is
 * when the null character is encountered, indicating the end of the string.
 * In this case, the function returns without printing anything. Otherwise, the
 * function makes a recursive call with the next character in the string (s + 1)
 * before printing the current character using putchar(*s).
 *
 * @s: The string to be printed in reverse.
 */
void _print_rev_recursion(char *s)
{
    if (*s == '\0')
        return;

    _print_rev_recursion(s + 1);
    putchar(*s);
}

int main(void)
{
    char *str = "Hello, World!";
    _print_rev_recursion(str);  // Call the function to print the string in reverse
    putchar('\n'); // Print a newline character after the reversed string
    return (0);
}

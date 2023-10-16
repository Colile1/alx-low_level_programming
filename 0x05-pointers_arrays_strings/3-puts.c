#include <unistd.h>

/**
 * _puts - Print a string to stdout, followed by a new line.
 * @str: The string to be printed.
 */
void _puts(char *str)
{
    char *p = str;

    while (*p)
    {
        write(1, p, 1); // Write each character to stdout
        p++;
    }
    write(1, "\n", 1); // Print a new line at the end
}

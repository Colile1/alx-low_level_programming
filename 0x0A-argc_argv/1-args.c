#include <stdio.h>

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the program's command-line arguments
 *
 * Return: 0 if successful, 1 if no arguments were passed
 */
int main(int argc, char *argv[])
{
    if (argc > 0)
    {
        printf("%d\n", argc - 1);
        return (0);
    }
    else
    {
        return (1);
    }
}

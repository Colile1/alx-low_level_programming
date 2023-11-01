#include <stdio.h>

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the program's command-line arguments
 *
 * Return: 0
 */

int main(int argc, char *argv [])
{
    int index;
    
    for (index = 0; index < argc; index++)
    {
        printf("%s\\n", argv [index]);
    }

    return 0;
}

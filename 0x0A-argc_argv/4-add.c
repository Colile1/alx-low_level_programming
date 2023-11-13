#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 if successful, 1 if there is an error
 */
int main(int argc, char *argv[])
{
    int sum = 0;
    int i;

    if (argc < 2)
    {
        printf("0\n");
        return (0);
    }

    for (i = 1; i < argc; i++)
    {
        char *endptr;
        long num = strtol(argv[i], &endptr, 10);

        if (*endptr != '\0' || num < 0)
        {
            printf("Error\n");
            return (1);
        }

        sum += num;
    }

    printf("%d\n", sum);
    return (0);
}

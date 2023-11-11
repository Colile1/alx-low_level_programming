#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiply two numbers.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("%d\n", num1 * num2);

    return 0;
}

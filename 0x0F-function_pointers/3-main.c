#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"
#include "function_pointers.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on wrong number of arguments,
 * 99 on invalid operator, 100 on division/modulo by zero
 */
int main(int argc, char *argv[])
{
    int num1, num2, result;
    int (*func)(int, int);

    if (argc != 4)
    {
        printf("Error\n");
        exit(98);
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);

    func = get_op_func(argv[2]);

    result = func(num1, num2);

    printf("%d\n", result);

    return (0);
}

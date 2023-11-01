#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
#include <stdio.h>

int main(int argc, char *argv [])
{
    printf("%d\\n", argc - 1);
    for (int i = 1; i < argc; i++)
    {
        printf("%s\\n", argv [i]);
    }

    return 0;
}

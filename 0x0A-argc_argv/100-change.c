#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the program's command-line arguments
 *
 * Return: 0 if successful, 1 if invalid arguments
 */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    int cents = atoi(argv[1]);
    if (cents < 0) {
        printf("0\n");
        return 0;
    }

    int coins = 0;
    int denominations[] = {25, 10, 5, 2, 1};
    for (int i = 0; i < sizeof(denominations) / sizeof(int); i++) {
        coins += cents / denominations[i];
        cents %= denominations[i];
    }

    printf("%d\n", coins);
    return 0;
}

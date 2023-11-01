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

    int quarters = cents / 25;
    cents %= 25;
    int dimes = cents / 10;
    cents %= 10;
    int nickels = cents / 5;
    cents %= 5;
    int pennies = cents;

    int totalCoins = quarters + dimes + nickels + pennies;
    printf("%d\n", totalCoins);

    return 0;
}
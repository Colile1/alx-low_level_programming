#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the program's command-line arguments
 *
 * Return: 0 if successful, 1 if there is an error
 */
int main(int argc, char *argv[]) 
{
int cents;
int coins[] = {25, 10, 5, 2, 1};
int numCoins = 0;
int i;

if (argc != 2)
{
printf("Error\n");
return (1);
}

cents = atoi(argv[1]);

if (cents < 0)
{
printf("0\n");
return (0);
}

for (i = 0; i < 5; i++)
{
while (cents >= coins[i])
{
cents -= coins[i];
numCoins++;
}
}

printf("%d\n", numCoins);
return (0);
}

#include <stdio.h>

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc > 0)
		printf("%s\n", argv[0]);
	return (0);
}

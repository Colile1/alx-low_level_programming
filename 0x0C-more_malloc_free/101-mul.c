#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * is_digit - Check if a string contains only digits
 * @str: The string to check
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_digit(char *str)
{
if (!str)
return (0);

while (*str)
{
if (*str < '0' || *str > '9')
return (0);
str++;
}

return (1);
}

/**
 * print_error - Print an error message and exit with status 98
 */

void print_error(void)
{
printf("Error\n");
exit(98);
}

/**
 * multiply - Multiply two numbers represented as strings
 * @num1: The first number
 * @num2: The second number
 */
void multiply(char *num1, char *num2)
{
int len1 = 0, len2 = 0, i, j, carry, n1, n2, sum, tmp;
int *result;

while (num1[len1])
len1++;
while (num2[len2])
len2++;

result = malloc(sizeof(int) * (len1 + len2));
if (!result)
print_error();

for (i = 0; i < len1 + len2; i++)
result[i] = 0;

for (i = len1 - 1; i >= 0; i--)
{
carry = 0;
n1 = num1[i] - '0';
j = len2 - 1;

for (; j >= 0; j--)
{
n2 = num2[j] - '0';
sum = n1 * n2 + result[i + j + 1] + carry;
carry = sum / 10;
result[i + j + 1] = sum % 10;
}
result[i + j + 1] = carry;
}

i = 0;
while (result[i] == 0)
i++;

tmp = len1 + len2 - i;
for (j = 0; j < tmp; j++)
putchar(result[i + j] + '0');
putchar('\n');
free(result);
}

/**
 * main - Multiplies two numbers
 * @argc: The number of arguments
 * @argv: The argument vector
 * Return: 0 on success, 1 on error
*/
int main(int argc, char *argv[])
{
if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
print_error();

multiply(argv[1], argv[2]);

return (0);
}



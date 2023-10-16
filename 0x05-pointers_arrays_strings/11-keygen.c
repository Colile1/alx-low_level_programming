#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generate random valid passwords for 101-crackme
 *
 * Return: Always 0
 */
int main(void)
{
    char password[84];
    int sum = 0;
    int i, r;

    srand(time(NULL));

    for (i = 0; sum < 2772 - 122; i++)
    {
        r = rand() % 62;
        password[i] = (r < 10) ? '0' + r : (r < 36) ? 'a' + r - 10 : 'A' + r - 36;
        sum += password[i];
    }

    password[i] = 2772 - sum - '0';
    i++;

    password[i] = '\0';

    printf("%s", password);

    return (0);
}

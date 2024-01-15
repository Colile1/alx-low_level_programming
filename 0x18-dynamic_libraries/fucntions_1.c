#include <stdio.h>

int _putchar(char c);
int _islower(int c);
int _isalpha(int c);
int _abs(int n);
int _isupper(int c);

int main(void)
{
    _putchar('H');
    printf("\n_islower('a') = %d\n", _islower('a'));
    printf("_isalpha('9') = %d\n", _isalpha('9'));
    printf("_abs(-98) = %d\n", _abs(-98));
    printf("_isupper('D') = %d\n", _isupper('D'));

    return 0;
}
int _putchar(char c)
{
    return write(1, &c, 1);
}

int _islower(int c)
{
    return (c >= 'a' && c <= 'z');
}

int _isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int _abs(int n)
{
    return (n >= 0 ? n : -n);
}

int _isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

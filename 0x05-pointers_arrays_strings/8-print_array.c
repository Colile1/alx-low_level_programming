void print_array(int *a, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        _putchar('0' + a[i]);
        if (i < n - 1)
        {
            _putchar(',');
            _putchar(' ');
        }
    }
    _putchar('\n');
}

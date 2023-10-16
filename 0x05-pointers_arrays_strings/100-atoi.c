/**
 * _atoi - Converts a string to an integer.
 * @s: A pointer to a string.
 *
 * Description: This function takes a pointer to a string as a parameter
 * and converts the string to an integer. It takes into account negative
 * and positive signs and returns the resulting integer.
 * If there are no numbers in the string, it returns 0.
 * Return: The converted integer.
 */
int _atoi(char *s)
{
int sign = 1;
int result = 0;
int i = 0;

if (s[0] == '-')
{
sign = -1;
i = 1;
}

while (s[i] != '\0')
{
if (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
}
else
{
break;
}
i++;
}

return (sign *result);
}

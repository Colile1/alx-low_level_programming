/**
 * wildcmp - Compares two strings with wildcards.
 * @s1: The first string.
 * @s2: The second string with wildcards.
 *
 * Return: 1 if identical, 0 if not.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		if (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)))
			return (1);

		return (0);
	}

	if (*s1 == *s2)
		return (*s1 == '\0' ? 1 : wildcmp(s1 + 1, s2 + 1));

	return (0);
}

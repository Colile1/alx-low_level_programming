/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The string to check.
 *
 * Return: 1 if the string is a palindrome, 0 if not.
 */
int is_palindrome(char *s)
{
	int length = _strlen_recursion(s);
	if (length <= 1)
		return (1);

	return (is_palindrome_check(s, 0, length - 1));
}

/**
 * is_palindrome_check - Helper function for is_palindrome.
 * @s: The string to check.
 * @start: The starting index.
 * @end: The ending index.
 *
 * Return: 1 if it's a palindrome, 0 if not.
 */
int is_palindrome_check(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (is_palindrome_check(s, start + 1, end - 1));
}

/**
 * _strlen_recursion - Returns the length of a string.
 * @s: Pointer to the string.
 *
 * Return: Length of the string.
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

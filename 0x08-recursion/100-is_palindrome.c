#include "main.h"

/**
 * _strlen - Calculate the length of a string.
 * @s: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	if (*s)
		return (1 + _strlen(s + 1));
	return (0);
}

/**
 * check_palindrome - Check if a string is a palindrome.
 * @s: The string to be checked.
 * @start: The index for the start of the comparison.
 * @end: The index for the end of the comparison.
 *
 * Return: 1 if it's a palindrome, 0 otherwise.
 */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end])
		return (0);
	return (check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome - Check if a string is a palindrome.
 * @s: The string to be checked.
 *
 * Return: 1 if it's a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int len = _strlen(s);

	if (len == 0)
		return (1);

	return (check_palindrome(s, 0, len - 1));
}

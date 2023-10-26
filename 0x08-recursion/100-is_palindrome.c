#include "main.h"
#include <string.h>

/**
 * is_palindrome_recursive - helper function to check if a string is a palindrome
 *
 * @s: input string
 * @start: starting index
 * @end: ending index
 *
 * Return: 1 if the string is a palindrome, 0 if not.
 */
int is_palindrome_recursive(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] == s[end])
		return (is_palindrome_recursive(s, start + 1, end - 1));

	return (0);
}

/**
 * is_palindrome - check if a string is a palindrome
 *
 * @s: input string
 *
 * Return: 1 if the string is a palindrome, 0 if not.
 */
int is_palindrome(char *s)
{
	int len = strlen(s);

	return (is_palindrome_recursive(s, 0, len - 1));
}

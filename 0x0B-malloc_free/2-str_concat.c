#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: A pointer to a newly allocated string containing s1 followed by s2,
 * or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
    char *concatenated;
    unsigned int len1, len2, i, j;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    for (len1 = 0; s1[len1]; len1++)
        ;
    for (len2 = 0; s2[len2]; len2++)
        ;

    concatenated = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (concatenated == NULL)
        return (NULL);

    for (i = 0; i < len1; i++)
        concatenated[i] = s1[i];
    for (j = 0; j < len2; j++, i++)
        concatenated[i] = s2[j];

    concatenated[i] = '\0';
    return (concatenated);
}

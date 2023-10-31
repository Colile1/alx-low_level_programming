#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
int count = 0;
int in_word = 0;

while (*str)
{
if (*str == ' ' || *str == '\t' || *str == '\n')
{
if (in_word)
in_word = 0;
}
else if (!in_word)
{
in_word = 1;
count++;
}
str++;
}

return count;
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words).
 */
char **strtow(char *str)
{
    char **words;
    int num_words, i, word_len, j = 0;

    if (str == NULL || *str == '\0' || count_words(str) == 0)
        return NULL;

    num_words = count_words(str);

    words = (char **)malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    for (i = 0; i < num_words; i++)
    {
        while (*str == ' ' || *str == '\t' || *str == '\n')
            str++;

        word_len = 0;
        while (str[word_len] != ' ' && str[word_len] != '\t' && str[word_len] != '\n' && str[word_len] != '\0')
            word_len++;

        words[i] = (char *)malloc((word_len + 1) * sizeof(char));
        if (words[i] == NULL)
        {
            while (i >= 0)
                free(words[i--]);
            free(words);
            return NULL;
        }

        for (j = 0; j < word_len; j++)
            words[i][j] = *str++;

        words[i][j] = '\0';
    }

    words[num_words] = NULL;
    return words;
}

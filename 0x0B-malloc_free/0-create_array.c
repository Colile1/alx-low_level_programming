#include <stdlib.h>

/**
 * create_array - Creates an array of chars and initializes it with a char.
 * @size: The size of the array to create.
 * @c: The character with which to initialize the array.
 *
 * Return: If size is 0 or if memory allocation fails, returns NULL.
 *         Otherwise, returns a pointer to the newly created array.
 */
char *create_array(unsigned int size, char c)
{
    char *arr;
    unsigned int i;

    if (size == 0)
        return (NULL);

    arr = (char *)malloc(size * sizeof(char));

    if (arr == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
        arr[i] = c;

    return (arr);
}

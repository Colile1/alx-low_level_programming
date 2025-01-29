#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Jump search algorithm
 * @array: Pointer to first element
 * @size: Array size
 * @value: Value to find
 * Return: Index of value or -1
 */
int jump_search(int *array, size_t size, int value)
{
    size_t jump = sqrt(size), i, prev;

    if (!array)
        return (-1);

    for (i = 0; i < size && array[i] < value; prev = i, i += jump)
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);

    printf("Value found between indexes [%lu] and [%lu]\n", prev, i);

    i = i < size ? i : size - 1;
    for (; prev <= i && array[prev] <= value; prev++)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
        if (array[prev] == value)
            return (prev);
    }

    return (-1);
}

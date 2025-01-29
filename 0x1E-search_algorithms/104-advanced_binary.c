#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary_rec - Recursive advanced binary search
 * @array: Array to search
 * @left: Left index
 * @right: Right index
 * @value: Value to find
 * Return: First index of value or -1
 */
int advanced_binary_rec(int *array, size_t left, size_t right, int value)
{
    size_t mid, i;

    if (right < left)
        return (-1);

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
        printf("%d%s", array[i], i < right ? ", " : "\n");

    mid = left + (right - left) / 2;
    
    if (array[mid] == value && (mid == left || array[mid - 1] != value))
        return (mid);
    if (array[mid] >= value)
        return (advanced_binary_rec(array, left, mid, value));
    return (advanced_binary_rec(array, mid + 1, right, value));
}

/**
 * advanced_binary - Advanced binary search
 * @array: Pointer to first element
 * @size: Array size
 * @value: Value to find
 * Return: Index of value or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array)
        return (-1);
    return (advanced_binary_rec(array, 0, size - 1, value));
}

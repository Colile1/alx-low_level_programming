#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * binary_search_exp - Binary search helper
 * @array: Array to search
 * @left: Left index
 * @right: Right index
 * @value: Value to find
 * Return: Index of value or -1
 */
int binary_search_exp(int *array, size_t left, size_t right, int value)
{
    size_t mid, i;

    while (left <= right)
    {
        printf("Searching in array: ");
        for (i = left; i <= right; i++)
            printf("%d%s", array[i], i < right ? ", " : "\n");
        
        mid = left + (right - left) / 2;
        if (array[mid] == value)
            return (mid);
        if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (-1);
}

/**
 * exponential_search - Exponential search algorithm
 * @array: Pointer to first element
 * @size: Array size
 * @value: Value to find
 * Return: Index of value or -1
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;

    if (!array)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           bound / 2, bound < size ? bound : size - 1);
    
    return binary_search_exp(array, bound / 2, 
                            (bound < size ? bound : size - 1), value);
}

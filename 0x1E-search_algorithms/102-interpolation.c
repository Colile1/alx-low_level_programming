#include <stdio.h>
#include "search_algos.h"

/**
 * interpolation_search - Interpolation search algorithm
 * @array: Pointer to first element
 * @size: Array size
 * @value: Value to find
 * Return: Index of value or -1
 */
int interpolation_search(int *array, size_t size, int value)
{
    size_t low = 0, high = size - 1, pos;

    if (!array)
        return (-1);

    while (low <= high && value >= array[low] && value <= array[high])
    {
        pos = low + (((double)(high - low) / 
              (array[high] - array[low])) * (value - array[low]));
        
        if (pos >= size)
        {
            printf("Value checked array[%lu] is out of range\n", pos);
            break;
        }

        printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
        
        if (array[pos] == value)
            return (pos);
        if (array[pos] < value)
            low = pos + 1;
        else
            high = pos - 1;
    }
    
    printf("Value checked array[%lu] is out of range\n", pos);
    return (-1);
}

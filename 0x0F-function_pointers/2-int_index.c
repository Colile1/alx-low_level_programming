/* 2-int_index.c */
#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array.
 * @array: The array to be searched.
 * @size: The number of elements in the array.
 * @cmp: The function pointer to the comparison function.
 *
 * Return: The index of the first element for which cmp does not return 0,
 * or -1 if no such element is found or size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
if (array != NULL && cmp != NULL && size > 0)
{
int i;

for (i = 0; i < size; i++)
{
if (cmp(array[i]) != 0)
return (i);
}
}

return (-1);
}

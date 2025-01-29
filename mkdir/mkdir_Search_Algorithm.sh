#!/bin/bash

# Create the project directory
mkdir -p search_algorithms

# Create README.md
echo "# Search Algorithms

This project contains implementations of linear search and binary search algorithms, along with Big O notation analysis." > search_algorithms/README.md

# Create the header file search_algos.h with include guards
cat <<EOL > search_algorithms/search_algos.h
#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
EOL

# Create 0-linear.c with linear search implementation
cat <<EOL > search_algorithms/0-linear.c
#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - Searches for a value using Linear Search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: First index where value is found, or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
    size_t i;

    if (array == NULL)
        return (-1);

    for (i = 0; i < size; i++)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return (i);
    }

    return (-1);
}
EOL

# Create 1-binary.c with binary search implementation
cat <<EOL > search_algorithms/1-binary.c
#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search - Searches for a value using Binary Search algorithm
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is found, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
    size_t left = 0, right = size - 1, mid, i;

    if (array == NULL)
        return (-1);

    while (left <= right)
    {
        printf("Searching in array: ");
        for (i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        mid = left + (right - left) / 2;
        if (array[mid] == value)
            return (mid);
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (-1);
}
EOL

# Create Big O notation files
echo "O(n)" > search_algorithms/2-O
echo "O(1)" > search_algorithms/3-O
echo "O(log n)" > search_algorithms/4-O
echo "O(1)" > search_algorithms/5-O
echo "O(nm)" > search_algorithms/6-O

# Ensure all files end with a newline (Linux-compatible)
for file in search_algorithms/*; do
    if [ -f "$file" ]; then
        sed -i -e '$a\' "$file"
    fi
done

echo "Project structure created successfully in 'search_algorithms' directory."
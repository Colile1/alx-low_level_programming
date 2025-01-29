#!/bin/bash

# Create project directory if needed
mkdir -p search_algorithms

# Update header file with new structs and prototypes
cat <<EOL > search_algorithms/search_algos.h
#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>
#include <stdio.h>
#include <math.h>

/* Basic search algorithms */
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);

/* Linked list structures */
typedef struct listint_s
{
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;

typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

/* Linked list search algorithms */
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* SEARCH_ALGOS_H */
EOL

# Create 100-jump.c
cat <<EOL > search_algorithms/100-jump.c
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
EOL

# Create 101-O
echo "O(sqrt(n))" > search_algorithms/101-O

# Create 102-interpolation.c
cat <<EOL > search_algorithms/102-interpolation.c
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
EOL

# Create 103-exponential.c
cat <<EOL > search_algorithms/103-exponential.c
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
EOL

# Create 104-advanced_binary.c
cat <<EOL > search_algorithms/104-advanced_binary.c
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
EOL

# Create 105-jump_list.c
cat <<EOL > search_algorithms/105-jump_list.c
#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Jump search on linked list
 * @list: Pointer to list head
 * @size: List size
 * @value: Value to find
 * Return: Pointer to node or NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t jump = sqrt(size), i;
    listint_t *current = list, *prev = NULL;

    if (!list)
        return (NULL);

    while (current->next && current->n < value)
    {
        prev = current;
        for (i = 0; current->next && i < jump; i++)
            current = current->next;
        
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           prev ? prev->index : 0, current->index);

    while (prev && prev->index <= current->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
    }

    return (NULL);
}
EOL

# Create 106-linear_skip.c
cat <<EOL > search_algorithms/106-linear_skip.c
#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - Linear skip search
 * @list: Pointer to list head
 * @value: Value to find
 * Return: Pointer to node or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express = list, *prev = list;

    if (!list)
        return (NULL);

    while (express->express && express->n < value)
    {
        prev = express;
        express = express->express;
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           prev->index, express->index);

    while (prev && prev->index <= express->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
    }

    return (NULL);
}
EOL

# Create Big O files
echo "O(sqrt(n))" > search_algorithms/107-O
echo "O(sqrt(n))" > search_algorithms/108-O

# Ensure all files end with newline (Linux compatible)
for file in search_algorithms/*; do
    if [ -f "$file" ]; then
        sed -i -e '$a\' "$file"
    fi
done

echo "Advanced tasks files created successfully!"
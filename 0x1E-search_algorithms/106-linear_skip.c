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

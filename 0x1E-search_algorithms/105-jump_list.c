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

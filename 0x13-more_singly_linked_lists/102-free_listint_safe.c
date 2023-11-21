#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list
 * @h: Double pointer to the head of the list
 *
 * Return: The number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *current, *next;

    if (h == NULL || *h == NULL)
        return (count);

    current = *h;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        count++;

        if (current <= next)
        {
            printf("Loop detected, freeing stopped\n");
            break;
        }

        current = next;
    }

    *h = NULL;
    return (count);
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely
 * @h: Double pointer to the head of the list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
    size_t size = 0;
    listint_t *tmp;

    if (h == NULL || *h == NULL)
        return (0);

    while (*h != NULL)
    {
        size++;
        if (*h <= (*h)->next)
        {
            tmp = *h;
            *h = (*h)->next;
            free(tmp);
            break;
        }
        tmp = *h;
        *h = (*h)->next;
        free(tmp);
    }

    *h = NULL;
    return (size);
}

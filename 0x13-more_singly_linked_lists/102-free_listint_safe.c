#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to the head of the list
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *slow, *fast, *loop, *tmp;

    if (h == NULL || *h == NULL)
        return (0);

    slow = fast = *h;
    /* detect loop using Floyd's cycle-finding algorithm */
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) /* loop found */
        {
            loop = slow;
            break;
        }
    }
    /* if no loop, free the list normally */
    if (loop == NULL)
    {
        while (*h)
        {
            tmp = *h;
            *h = (*h)->next;
            free(tmp);
            count++;
        }
    }
    else /* if loop, free the list until loop point */
    {
        while (*h != loop)
        {
            tmp = *h;
            *h = (*h)->next;
            free(tmp);
            count++;
        }
        /* free the loop node and the next node */
        tmp = *h;
        *h = (*h)->next;
        free(tmp);
        count++;
        tmp = *h;
        *h = NULL;
        free(tmp);
    }
    return (count);
}

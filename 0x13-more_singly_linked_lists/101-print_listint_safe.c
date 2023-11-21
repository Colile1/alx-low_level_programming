#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: Pointer to the head of the list
 *
 * Return: Number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *current = head;
    size_t count = 0;

    while (current)
    {
        /* Print the current node */
        printf("[%p] %d\n", (void *)current, current->n);
        count++;

        if (current <= current->next)
        {
            /* Print the looped node and exit the loop */
            printf("-> [%p] %d\n", (void *)current->next, current->next->n);
            break;
        }

        current = current->next;
    }

    return (count);
}

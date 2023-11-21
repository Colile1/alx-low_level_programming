#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

size_t print_listint_safe(const listint_t *head)
{
    const listint_t *current = head;
    size_t count = 0;

    while (current != NULL)
    {
        printf("[%p] %d\n", (void *)current, current->n);
        count++;
        if (current <= current->next)
        {
            printf("-> [%p] %d\n", (void *)current->next, current->next->n);
            printf("-> List contains a loop\n");
            exit(98);
        }
        current = current->next;
    }

    return count;
}

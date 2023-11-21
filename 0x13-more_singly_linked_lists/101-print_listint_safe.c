#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

size_t print_listint_safe(const listint_t *head)
{
    const listint_t *current = head;
    size_t count = 0;
    const listint_t *loop_node = NULL;

    while (current != NULL)
    {
        if (current == loop_node)
            break;

        printf("[%p] %d\n", (void *)current, current->n);
        count++;

        if (current->next == loop_node)
            break;

        current = current->next;

        if (loop_node == NULL && current != NULL && current->next != NULL)
            loop_node = current->next;
    }

    if (loop_node != NULL)
        printf("-> [%p] %d\n", (void *)loop_node, loop_node->n);

    return (count);
}

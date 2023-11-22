#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    const listint_t *current = head;
    const listint_t *loop_start = find_listint_loop((listint_t *)head);

    while (current != NULL && current != loop_start)
    {
        printf("[%p] %d\n", (void *)current, current->n);
        current = current->next;
        count++;
    }

    if (current == loop_start)
    {
        printf("-> [%p] %d\n", (void *)current, current->n);
        count++;
    }

    if (current != NULL)
    {
        printf("-> [%p] %d\n", (void *)current, current->n);
        printf("Error: linked list contains a loop\n");
        exit(98);
    }

    return count;
}

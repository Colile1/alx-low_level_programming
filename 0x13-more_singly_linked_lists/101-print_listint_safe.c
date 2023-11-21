#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *current = head;
size_t count = 0;

while (current != NULL && current != current->next)
{
printf("[%p] %d\n", (void *)current, current->n);
count++;
current = current->next;
}

if (current != NULL)
{
printf("[%p] %d\n", (void *)current, current->n);
printf("-> [%p] %d\n", (void *)current->next, current->next->n);
}

return (count);
}

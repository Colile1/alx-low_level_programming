#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: Pointer to the head of the list
 *
 * Description: Number of nodes in the list
 */

/**
 * print_listint - Prints a listint_t linked list
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */

size_t print_listint(const listint_t *head)
{
    const listint_t *current = head;
    size_t count = 0;

    while (current)
    {
        printf("%d\n", current->n);
        count++;
        current = current->next;
    }

    return count;
}


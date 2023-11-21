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
    const listint_t *slow = head;
    const listint_t *fast = head;
    size_t count = 0;
    int loop_found = 0;

    if (head == NULL)
        exit(98);

    while (slow && fast && fast->next)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            loop_found = 1;
            break;
        }

        count++;
    }

    if (loop_found)
    {
        printf("-> [%p] %d\n", (void *)slow, slow->n);
        return (count);
    }

    slow = head;
    while (slow)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        slow = slow->next;
        count++;
    }

    return (count);
}


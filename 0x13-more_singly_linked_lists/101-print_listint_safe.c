#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a linked list safely (handles loops)
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    const listint_t *slow, *fast, *loop;

    if (head == NULL)
        exit(98);

    slow = fast = head;
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
    /* if no loop, print the list normally */
    if (loop == NULL)
    {
        while (head)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
            count++;
        }
    }
    else /* if loop, print the list until loop point */
    {
        const listint_t *temp = head;
        do
        {
            printf("[%p] %d\n", (void *)temp, temp->n);
            temp = temp->next;
            count++;
        } while (temp != loop);
        /* print the loop node and the next node */
        printf("[%p] %d\n", (void *)temp, temp->n);
        temp = temp->next;
        count++;
        printf("-> [%p] %d\n", (void *)temp, temp->n);
        while (temp != loop)
        {
            printf("[%p] %d\n", (void *)temp, temp->n);
            temp = temp->next;
            count++;
        }
    }
    return (count);
}


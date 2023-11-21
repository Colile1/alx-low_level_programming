#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head of the list
 * 
 * Return: the number of nodes in the list
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
        while (head != loop)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
            count++;
        }
        /* print the loop node and the next node */
        printf("[%p] %d\n", (void *)head, head->n);
        head = head->next;
        count++;
        printf("-> [%p] %d\n", (void *)head, head->n);
    }
    return (count);
}

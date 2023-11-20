#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* delete_nodeint_at_index - Deletes the node at index
* @head: Double pointer to the head of the list
* @index: Index of the node to be deleted
*
* Return: 1 if it succeeded, -1 if it failed
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current, *prev;
unsigned int count = 0;

if (*head == NULL)
return (-1);

if (index == 0)
{
current = *head;
*head = (*head)->next;
free(current);
return (1);
}

current = *head;
while (current != NULL)
{
if (count == index)
{
prev->next = current->next;
free(current);
return (1);
}
prev = current;
current = current->next;
count++;
}

return (-1);
}

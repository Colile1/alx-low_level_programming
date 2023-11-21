#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Pointer to the head of the list
 * @idx: Index where the new node should be added
 * @n: Value to be assigned to the new node
 *
 * Return: The address of the new node, or NULL if it failed to insert
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node, *temp, *prev;
unsigned int i;

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
{
return (NULL);
}

new_node->n = n;

if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}
temp = *head;
prev = NULL;
for (i = 0; i < idx && temp != NULL; i++)
{
prev = temp;
temp = temp->next;
}

if (i < idx)
{
free(new_node);
return (NULL);
}

new_node->next = temp;
prev->next = new_node;

return (new_node);
}

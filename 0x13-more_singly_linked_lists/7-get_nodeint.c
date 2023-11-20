#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* get_nodeint_at_index - Gets the node at the given index in a listint_t list
 * @head: Pointer to the head of the list
 * @index: Index of the node to be retrieved
 *
 * Return: The node at the given index, or NULL if the index is out of range
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int count = 0;
listint_t *current = head;

while (current != NULL)
{
if (count == index)
return (current);
count++;
current = current->next;
}

return (NULL);
}

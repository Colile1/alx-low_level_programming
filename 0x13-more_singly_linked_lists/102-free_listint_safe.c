#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @h: Pointer to a pointer to the beginning of the linked list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *current = *h;
listint_t *temp = NULL;
size_t count = 0;

while (current != NULL)
{
count++;
if (current <= current->next)
{
temp = current->next;
current->next = NULL;
break;}
temp = current->next;
free(current);
current = temp;
}

*h = NULL;
return (count);
}

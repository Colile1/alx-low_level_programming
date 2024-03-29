#include "lists.h"

/**
 * print_dlistint - print dlinked list.
 * @h: pointer to head
 *
 * Description: function that prints all the elements of a dLinked List.
 * Return: number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t size;

	size = 0;
	while (h)
	{
		printf("%d\n", h->n);
		size++;
		h = h->next;
	}
	return (size);
}

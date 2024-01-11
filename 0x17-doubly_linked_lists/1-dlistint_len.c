#include "lists.h"

/**
 * dlistint_len - size of dLlist
 * @h: pointer to head
 *
 * Description: function that  number of elements in a dLinked List.
 * Return: number of nodes.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t size;

	size = 0;
	while (h)
	{
		size++;
		h = h->next;
	}
	return (size);
}

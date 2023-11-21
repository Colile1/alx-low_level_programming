#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

size_t free_listint_safe(listint_t **h)
{
    listint_t *tmp;
    listint_t *current;
    size_t count = 0;

    if (!h || !*h)
        return (0);

    current = *h;  
    while (current) {
        tmp = current->next;
        free(current);
        current = tmp;
        count++;
    }

    *h = NULL;
    return (count);
}

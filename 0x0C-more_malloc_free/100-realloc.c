#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: A pointer to the previously allocated memory
 * @old_size: The size of the allocated space
 * @new_size: The new size of the memory block
 *
 * Return: A pointer to the reallocated memory, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *new_ptr;
unsigned int i, min_size;

if (new_size == old_size)
return (ptr);

if (ptr == NULL)
return (malloc(new_size));

if (new_size == 0)
{
free(ptr);
return (NULL);
}

new_ptr = malloc(new_size);

if (new_ptr == NULL)
return (NULL);

min_size = (old_size < new_size) ? old_size : new_size;

for (i = 0; i < min_size; i++)
((char *)new_ptr)[i] = ((char *)ptr)[i];

free(ptr);
return (new_ptr);
}

#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - Allocates memory using malloc
 * @size: The size of memory to allocate
 *
 * Return: A pointer to the allocated memory
 */

void *malloc_checked(unsigned int size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(98);
    }
    return ptr;
}
#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - Allocates memory using malloc
 * @b: The size of memory to allocate
 *
 * Return: A pointer to the allocated memory
 */

void *malloc_checked(unsigned int b) {
    void *p = malloc(b);
    if (p == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(98);
    }
    return p;
}
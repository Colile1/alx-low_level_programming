#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
* malloc_checked - Allocates memory using malloc
* @b: The size of memory to allocate
*
* Return: A pointer to the allocated memory
*/

void *malloc_checked(unsigned int b) {
void *ptr = malloc(b);
if (ptr == NULL) {
fprintf(stderr, "Error: malloc failed\n");
exit(98);
}
return (ptr);
}
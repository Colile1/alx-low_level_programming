#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/* Task 0: What's my name */
void print_name(char *name, void (*f)(char *));

/* Task 1: If you spend too much time thinking about a thing, you'll never get it done */
void array_iterator(int *array, size_t size, void (*action)(int));

/* Task 2: To hell with circumstances; I create opportunities */
int int_index(int *array, int size, int (*cmp)(int));

/* Task 3: A goal is not always meant to be reached, it often serves simply as something to aim at */
/* 3-calc.h contains the necessary structures and prototypes for the calculator program */

#endif /* FUNCTION_POINTERS_H */

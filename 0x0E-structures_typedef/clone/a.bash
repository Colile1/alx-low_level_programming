#!/bin/bash

# Task 0: Poppy
# Create dog.h file
echo 'typedef struct dog {
    char *name;
    float age;
    char *owner;
} dog_t;' > dog.h

# Task 1: A dog is the only thing on earth that loves you more than you love yourself
# Create 1-init_dog.c file
echo '#include "dog.h"

/**
 * init_dog - Initializes a variable of type struct dog
 * @d: Pointer to the struct dog
 * @name: Pointer to the name of the dog
 * @age: Age of the dog
 * @owner: Pointer to the owner's name
 *
 * Return: Void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d)
    {
        d->name = name;
        d->age = age;
        d->owner = owner;
    }
}' > 1-init_dog.c

# Task 2: A dog will teach you unconditional love. If you can have that in your life, things won't be too bad
# Create 2-print_dog.c file
echo '#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints the information of a struct dog
 * @d: Pointer to the struct dog
 *
 * Return: Void
 */
void print_dog(struct dog *d)
{
    if (d)
    {
        printf("Name: %s\n", (d->name) ? d->name : "(nil)");
        printf("Age: %.6f\n", d->age);
        printf("Owner: %s\n", (d->owner) ? d->owner : "(nil)");
    }
}' > 2-print_dog.c

# Task 3: Outside of a dog, a book is a man's best friend. Inside of a dog it's too dark to read
# Create 3-main.c file
echo '#include <stdio.h>
#include "dog.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    dog_t my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}' > 3-main.c

# Task 4: A door is what a dog is perpetually on the wrong side of
# Create 4-new_dog.c file
echo '#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: Pointer to the name of the dog
 * @age: Age of the dog
 * @owner: Pointer to the owner's name
 *
 * Return: Pointer to the newly created dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *new_dog;
    int name_length;
    int owner_length;
    int i;

    new_dog = malloc(sizeof(dog_t));
    if (new_dog == NULL)
        return (NULL);

    for (name_length = 0; name[name_length]; name_length++)
        ;
    for (owner_length = 0; owner[owner_length]; owner_length++)
        ;

    new_dog->name = malloc(sizeof(char) * (name_length + 1));
    if (new_dog->name == NULL)
    {
        free(new_dog);
        return (NULL);
    }
    for (i = 0; i <= name_length; i++)
        new_dog->name[i] = name[i];

    new_dog->age = age;

    new_dog->owner = malloc(sizeof(char) * (owner_length + 1));
    if (new_dog->owner == NULL)
    {
        free(new_dog->name);
        free(new_dog);
        return (NULL);
    }
    for (i = 0; i <= owner_length; i++)
        new_dog->owner[i] = owner[i];

    return (new_dog);
}' > 4-new_dog.c

# Task 5: How many legs does a dog have if you call his tail a leg? Four. Saying that a tail is a leg doesn't make it a leg
# Create 5-free_dog.c file
echo '#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees the memory allocated for a dog
 * @d: Pointer to the struct dog
 *
 * Return: Void
 */
void free_dog(dog_t *d)
{
    if (d)
    {
        free(d->name);
        free(d

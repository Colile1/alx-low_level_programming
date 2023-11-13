#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: Pointer to the name string
 * @age: Age of the dog
 * @owner: Pointer to the owner string
 *
 * Return: Pointer to the newly created dog, or NULL if fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *new_dog;
    char *name_copy, *owner_copy;
    int name_length = 0, owner_length = 0;
    int i;

    while (name[name_length])
        name_length++;

    while (owner[owner_length])
        owner_length++;

    new_dog = malloc(sizeof(dog_t));
    if (new_dog == NULL)
        return (NULL);

    name_copy = malloc(sizeof(char) * (name_length + 1));
    if (name_copy == NULL)
    {
        free(new_dog);
        return (NULL);
    }

    owner_copy = malloc(sizeof(char) * (owner_length + 1));
    if (owner_copy == NULL)
    {
        free(name_copy);
        free(new_dog);
        return (NULL);
    }

    for (i = 0; i <= name_length; i++)
        name_copy[i] = name[i];

    for (i = 0; i <= owner_length; i++)
        owner_copy[i] = owner[i];

    new_dog->name = name_copy;
    new_dog->age = age;
    new_dog->owner = owner_copy;

    return (new_dog);
}

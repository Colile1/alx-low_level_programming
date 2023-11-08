/**
 * array_iterator - Executes a given function on each element of an array
 * @array: The array
 * @size: The size of the array
 * @action: The function to be executed on each element
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        action(array[i]);
    }
}

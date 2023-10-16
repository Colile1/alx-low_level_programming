/**
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Description: This function takes two integer pointers as parameters
 * and swaps the values of the integers they point to.
 */
/* swap_int - Swaps the values of two integers.*/
void swap_int(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

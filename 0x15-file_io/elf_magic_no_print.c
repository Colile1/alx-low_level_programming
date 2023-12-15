#include "main.h"

/**
 * elf_magic_no_print - Prints the magic numbers of an ELF header.
 * @elf_array_pointer: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void elf_magic_no_print(unsigned char *elf_array_pointer)
{
	int index;
	printf("  Magic:   ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", elf_array_pointer[index]);
		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

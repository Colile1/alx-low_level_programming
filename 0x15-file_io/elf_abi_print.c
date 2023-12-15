#include "main.h"

/**
 * elf_abi_print - Prints the ABI version of an ELF header.
 * @elf_array_pointer: A pointer to an array containing the ELF ABI version.
 */
void elf_abi_print(unsigned char *elf_array_pointer)
{
	printf("  ABI Version:      %d\n",
	  elf_array_pointer[EI_ABIVERSION]);
}

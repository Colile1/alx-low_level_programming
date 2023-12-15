#include "main.h"

/**
 * elf_entry_print - Prints the entry point of an ELF header.
 * @elf_entry: The address of the ELF entry point.
 * @elf_array_pointer: A pointer to an array containing the ELF class.
 */
void elf_entry_print(unsigned long int elf_entry, unsigned char *elf_array_pointer)
{
	printf("  Entry point address:               ");

	if (elf_array_pointer[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
			  ((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (elf_array_pointer[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else
		printf("%#lx\n", elf_entry);
}

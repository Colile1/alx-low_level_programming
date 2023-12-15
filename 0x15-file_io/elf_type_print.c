#include "main.h"

/**
 * elf_type_print - Prints the type of an ELF header.
 * @elf_type: The ELF type.
 * @elf_array_pointer: A pointer to an array containing the ELF class.
 */
void elf_type_print(unsigned int elf_type, unsigned char *elf_array_pointer)
{
	if (elf_array_pointer[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf("  Type:                         ");

	switch (elf_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_type);
	}
}

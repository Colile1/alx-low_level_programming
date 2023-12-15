#include "main.h"

/**
 * elf_class_print - Prints the class of an ELF header.
 * @elf_array_pointer: A pointer to an array containing the ELF class.
 */
void elf_class_print(unsigned char *elf_array_pointer)
{
	printf("  Class:                        ");

	switch (elf_array_pointer[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_array_pointer[EI_CLASS]);
	}
}

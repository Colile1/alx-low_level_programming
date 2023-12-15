#include "main.h"

/**
 * elf_version_print - Prints the version of an ELF header.
 * @elf_array_pointer: A pointer to an array containing the ELF version.
 */
void elf_version_print(unsigned char *elf_array_pointer)
{
	printf("  Version:                           %d",
	       elf_array_pointer[EI_VERSION]);
	switch (elf_array_pointer[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

#include "main.h"

/**
 * elf_h_data_printer - Prints the data of an ELF header.
 * @elf_array_pointer: A pointer to an array containing the ELF class.
 */
void elf_h_data_printer(unsigned char *elf_array_pointer)
{
	printf("  Data:                         ");

	switch (elf_array_pointer[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_array_pointer[EI_CLASS]);
	}
}

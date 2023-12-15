#include "main.h"

/**
 * elf_checker - Checks if a file is an ELF file.
 * @elf_array_pointer: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void elf_checker(unsigned char *elf_array_pointer)
{
int index;

for (index = 0; index < 4; index++)
{
if (elf_array_pointer[index] != 127 &&
elf_array_pointer[index] != 'E' &&
elf_array_pointer[index] != 'L' &&
elf_array_pointer[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

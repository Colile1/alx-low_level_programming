#include "main.h"
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Displays the ELF header information of an ELF file.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success.
 *
 * Description: Terminates with exit code 98 if the file cannot be processed
 *              as a valid ELF file or in case of an error during the operations.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		elf_close(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		elf_close(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	elf_checker(header->elf_array_pointer);
	printf("ELF Header:\n");
	elf_magic_no_print(header->elf_array_pointer);
	elf_class_print(header->elf_array_pointer);
	elf_h_data_printer(header->elf_array_pointer);
	elf_version_print(header->elf_array_pointer);
	elf_osabi_print(header->elf_array_pointer);
	elf_abi_print(header->elf_array_pointer);
	elf_type_print(header->elf_type, header->elf_array_pointer);
	elf_entry_print(header->elf_entry, header->elf_array_pointer);

	free(header);
	elf_close(o);
	return (0);
}

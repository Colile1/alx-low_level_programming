#include <stdio.h>
#include <fcntl.h>
#include <elf.h>
#include <unistd.h>

/**
 * display_elf_header - Displays the information contained in the ELF
 * header.
 * @elf_header: A pointer to an Elf64_Ehdr structure containing the ELF
 * header.
 */
void display_elf_header(Elf64_Ehdr *elf_header)
{
int i;

printf("ELF Header:\n");
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", elf_header->e_ident[i]);
}
printf("\n");
printf("  Class:   %s\n", (elf_header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
printf("  Data:    %s\n", (elf_header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
printf("  Version: %d (current)\n", elf_header->e_ident[EI_VERSION]);
printf("  OS/ABI:  %s\n", (elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "UNIX - NetBSD"); /* Update with more OS/ABI options */
printf("  ABI Version:  %d\n", elf_header->e_ident[EI_ABIVERSION]);
printf("  Type:    %d\n", elf_header->e_type);
printf("  Entry point address:  0x%lx\n", elf_header->e_entry);
}

/**
 * main - Displays the information contained in the ELF header at the
 * beginning of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, error code otherwise.
 */
int main(int argc, char *argv[])
{
int fd;
Elf64_Ehdr elf_header;
ssize_t read_size;

if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
return (1);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
fprintf(stderr, "Failed to open file: %s\n", argv[1]);
return (1);
}

read_size = read(fd, &elf_header, sizeof(elf_header));
if (read_size != sizeof(elf_header))
{
fprintf(stderr, "Failed to read ELF header\n");
close(fd);
return (1);
}

display_elf_header(&elf_header);

close(fd);
return (0);
}

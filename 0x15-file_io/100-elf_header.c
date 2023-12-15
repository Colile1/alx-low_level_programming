#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>

void print_elf_header(int fd) {
Elf64_Ehdr header;
if (read(fd, &header, sizeof(header)) != sizeof(header)) {
fprintf(stderr, "Error reading ELF header\n");
exit(98);
}

if (header.e_ident[EI_MAG0] != ELFMAG0 || 
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 || 
header.e_ident[EI_MAG3] != ELFMAG3) {
fprintf(stderr, "Not an ELF file\n");
exit(98);
}

printf("Magic: ");
for (int i = 0; i < EI_NIDENT; i++) {
printf("%02x ", header.e_ident[i]);
}
printf("\n");

printf("Class: ");
switch (header.e_ident[EI_CLASS]) {
case ELFCLASS32: printf("ELF32\n"); break;
case ELFCLASS64: printf("ELF64\n"); break;
default: printf("Invalid class\n"); break;
}

printf("Data: ");
switch (header.e_ident[EI_DATA]) {
case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
default: printf("Invalid data encoding\n"); break;
}

printf("Version: %d", header.e_ident[EI_VERSION]);
if (header.e_ident[EI_VERSION] == EV_CURRENT) {
printf(" (current)\n");
} else {
printf("\n"); 
}

printf("OS/ABI: ");
switch (header.e_ident[EI_OSABI]) {
case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
case ELFOSABI_LINUX: printf("Linux\n"); break;
default: printf("Unknown\n"); break;
}

printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);

printf("Type: ");
switch (header.e_type) {
case ET_REL: printf("REL (Relocatable file)\n"); break;
case ET_EXEC: printf("EXEC (Executable file)\n"); break; 
case ET_DYN: printf("DYN (Shared object file)\n"); break;
default: printf("Unknown\n"); break;
}

printf("Entry point address: 0x%lx\n", header.e_entry);
}

int main(int argc, char *argv[]) {
if (argc != 2) {
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
exit(1);
}

int fd = open(argv[1], O_RDONLY);
if (fd == -1) {
perror("Error opening file");
exit(1);
}

print_elf_header(fd);

close(fd);
return 0;
}

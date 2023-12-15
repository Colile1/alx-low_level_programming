#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

#define BUFFER_SIZE 64

void display_error_message() {
    dprintf(STDERR_FILENO, "Error: Not an ELF file or encountered an error\n");
    exit(98);
}

void display_elf_header_info(const char *filename) {
    int fd, read_result;
    Elf64_Ehdr header;
    unsigned int i;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        display_error_message();
    }

    read_result = read(fd, &header, sizeof(header));
    if (read_result != sizeof(header)) {
        display_error_message();
    }

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        display_error_message();
    }

    printf("Magic: ");
    for (i = 0; i < SELFMAG; ++i) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\nClass: %s\n", (header.e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
    printf("Data: %s\n", (header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
    printf("Version: %d\n", header.e_ident[EI_VERSION]);
    printf("OS/ABI: %d\n", header.e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
    printf("Type: %d\n", header.e_type);
    printf("Entry point address: %lx\n", (unsigned long)header.e_entry);

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    display_elf_header_info(argv[1]);

    return (0);
}

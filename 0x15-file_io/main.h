#ifndef MAIN_H
#define MAIN_H
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Prototypes*/
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
void my_printf(const char *format, ...);
size_t get_line_length(const char *str);
char *my_strcat(char *dest, const char *src);

/*elf functions*/
void elf_checker(unsigned char *elf_array_pointer);
void elf_close(int elf);
void elf_abi_print(unsigned char *elf_array_pointer);
void elf_class_print(unsigned char *elf_array_pointer);
void elf_h_data_printer(unsigned char *elf_array_pointer);
void elf_entry_print(unsigned long int elf_entry, unsigned char *elf_array_pointer);
void elf_magic_no_print(unsigned char *elf_array_pointer);
void elf_osabi_print(unsigned char *elf_array_pointer);
void elf_type_print(unsigned int elf_type, unsigned char *elf_array_pointer);
void elf_version_print(unsigned char *elf_array_pointer);

#endif 

#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>

/* Function to read a text file and print it to the POSIX standard output */
ssize_t read_textfile(const char *filename, size_t letters);

/* Prototypes*/
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
void my_printf(const char *format, ...);
size_t get_line_length(const char *str);
char *my_strcat(char *dest, const char *src);


#endif 


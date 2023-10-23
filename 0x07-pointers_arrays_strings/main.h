#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
char *_memset(char *dest, char *src);
char *_memcpy(char *dest, char *src, int n);
char *_strchr(char *dest, char *src, int n);
int _strspn(char *s1, char *s2);
void _strpbrk(int *a, int n);
char *string_toupper(char *a);
char *cap_string(char *a);
char *leet(char *a);
char *rot13(char *a);
void print_number(int n);
char *infinite_add(char *n1, char *n2, char *r, int size_r);
void print_buffer(char *b, int size);

#endif


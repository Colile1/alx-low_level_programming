#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>

/* Function prototypes */

/* 0-isupper.c */
int _isupper(int c);

/* 0-memset.c */
char *_memset(char *s, char b, unsigned int n);

/* 0-strcat.c */
char *_strcat(char *dest, char *src);

/* 1-isdigit.c */
int _isdigit(int c);

/* 1-memcpy.c */
char *_memcpy(char *dest, char *src, unsigned int n);

/* 1-strncat.c */
char *_strncat(char *dest, char *src, int n);

/* 100-atoi.c */
int _atoi(char *s);

/* 2-strchr.c */
char *_strchr(char *s, char c);

/* 2-strlen.c */
int _strlen(char *s);

/* 2-strncpy.c */
char *_strncpy(char *dest, char *src, int n);

/* 3-islower.c */
int _islower(int c);

/* 3-puts.c */
void _puts(char *s);

/* 3-strcmp.c */
int _strcmp(char *s1, char *s2);

/* 3-strspn.c */
unsigned int _strspn(char *s, char *accept);

/* 4-isalpha.c */
int _isalpha(int c);

/* 4-strpbrk.c */
char *_strpbrk(char *s, char *accept);

/* 5-strstr.c */
char *_strstr(char *haystack, char *needle);

/* 6-abs.c */
int _abs(int n);

/* 9-strcpy.c */
char *_strcpy(char *dest, char *src);

/* _putchar.c */
int _putchar(char c);

#endif /* MAIN_H */

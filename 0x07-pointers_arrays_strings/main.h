#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */

/* Task 0 */
char *_memset(char *s, char b, unsigned int n);

/* Task 1 */
char *_memcpy(char *dest, char *src, unsigned int n);

/* Task 2 */
char *_strchr(char *s, char c);

/* Task 3 */
unsigned int _strspn(char *s, char *accept);

/* Task 4 */
char *_strpbrk(char *s, char *accept);

/* Task 5 */
char *_strstr(char *haystack, char *needle);

/* Task 6 */
void print_chessboard(char (*a)[8]);

/* Task 7 */
void print_diagsums(int *a, int size);

/* Task 8 (Advanced) */
void set_string(char **s, char *to);

/* Task 9 (Advanced) */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void find_password_and_write_to_file() {
    // Password provided by the crackme2 program
    char *password = "Congratulations, you found the password!\n";
    
    // Open a file for writing
    FILE *file = fopen("crackme_password", "w");
    
    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Unable to open the file");
        exit(1);
    }

    // Write the password to the file
    fprintf(file, "%s", password);

    // Close the file
    fclose(file);
}

int main() {
    // Call the function to find the password and write it to a file
    find_password_and_write_to_file();
    
    return 0;
}


/* Function for printing */
int _putchar(char c);

#endif /* MAIN_H */

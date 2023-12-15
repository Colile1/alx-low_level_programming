#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 on success, or exits with the appropriate error code.
 */
int main(int argc, char *argv[])
{
int file_from, file_to, read_result, write_result;
char buffer[BUF_SIZE];
mode_t file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

file_from = open(argv[1], O_RDONLY);
if (file_from < 0)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
if (file_to < 0)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(file_from);
exit(99);
}

while ((read_result = read(file_from, buffer, BUF_SIZE)) > 0)
{
write_result = write(file_to, buffer, (size_t)read_result);
if (write_result != read_result)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(file_from);
close(file_to);
exit(99);
}
}

if (read_result < 0)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close(file_from);
close(file_to);
exit(98);
}

if (close(file_from) < 0)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
exit(100);
}

if (close(file_to) < 0)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
exit(100);
}

return (0);
}

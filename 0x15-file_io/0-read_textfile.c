#include "main.h"
#include <unistd.h>
#include <fcntl.h>


/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters read and printed, or 0 if an error occurs
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char buffer[1024];
	int file_descriptor, bytes_read, bytes_written;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	bytes_read = read(file_descriptor, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
		close(file_descriptor);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		close(file_descriptor);
		return (0);
	}

	close(file_descriptor);
	return (bytes_written);
}

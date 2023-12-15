<<<<<<<<<<<<<<  ✨ Codeium Command ⭐ >>>>>>>>>>>>>>>>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
int file_descriptor;
int status;
int text_length = 0;

if (filename == NULL)
return (-1);

file_descriptor = open(filename, O_WRONLY | O_APPEND);
if (file_descriptor == -1)
return (-1);

if (text_content != NULL)
{
while (text_content[text_length])
text_length++;

status = write(file_descriptor, text_content, text_length);
close(file_descriptor);

if (status == -1 || status != text_length)
return (-1);
}
else
{
close(file_descriptor);
}

return (1);
}
<<<<<<<  336eb6fb-3787-442f-8991-ebe1f3b9c0b0  >>>>>>>
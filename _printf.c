#include "main.h"

/**
 * print_buffer - prints buffer
 * @buffer[]: arr
 * @buffer_ind: strinf
 */
void print_buffer(char buffer[], int *buffer_in);
/**
 * _printf - Entry point
 * @format: char
 * Return: int
 */
int _printf(const char *format, ...)
{
int i, prnt = 0, prnt_char = 0;
int flags, width;
int precision, size, buffer_in = 0;
va_list arg;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(arg, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buffer_in++] = format[i];
if (buffer_in == BUFF_SIZE)
print_buffer(buffer, &buffer_in);
prnt_char++;
}
else
{
print_buffer(buffer, &buffer_in);
flags = get_flags(format, &i);
width = get_width(format, &i, arg);
size = get_size(format, &i);
precision = get_precision(format, &i, arg);
++i;
prnt = handle_print(format, &i, arg, buffer,
		    flags, width, precision, size);
if (prnt == -1)
return (-1);
prnt_char += prnt;
}
}
print_buffer(buffer, &buffer_in);
va_end(arg);
return (prnt_char);
}
void print_buffer(char buffer[], int *buffer_in)
{
if (*buffer_in > 0)
write(1, &buffer[0], *buffer_in);
*buffer_in = 0;
}

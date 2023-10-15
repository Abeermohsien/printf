#include "main.h"
/**
 * _printf - Entry point
 * @format: char
 * Return: int
 */
int _printf(const char *format, ...)
{
char c;
int counter = 0;
va_list arg;
if (format == NULL)
return (-1);
va_start(arg, format);
if (*format != '%')
{
write(1, format, 1);
counter++;
}
else
{
format++;
if (*format == '\0')
{
return (counter);
}
else if (*format == '%')
{
write(1, format, 1);
counter++;
}
else if (*format == 'c')
{
c = va_arg(arg, int);
write(1, &c, 1);
counter++;
}
else if (*format == 's')
{
char *str = va_arg(arg, char*);
int len = 0;
while (str[len] != '\0')
len++;
write(1, str, len);
counter += len;
}
}
format++;
va_end(arg);
return (counter);
}

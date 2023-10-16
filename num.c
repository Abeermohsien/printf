#include "main.h"
/**
 * _isdigit - si digit
 * @c: char
 * Return: int
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * _strlen - string count
 * @s: string
 * Return: int
 *
 */
int _strlen(char *s)
{
	int n = 0;

	while (*s++)
		n++;
	return (n);
}
/**
 * print_number - prints numbber
 * @s: string
 * @params: param
 * Return: int
 */
int print_number(char *s, params_t *params)
{
	unsigned int n = _strlen(s);
	int num = (!params->unsign && *s == '-');

	if (!params->precision && *s == '0' && !s[1])
		s = "";
	if (num)
	{
		s++;
		n--;
	}
	if (params->precision != UINT_MAX)
			while (n++ < params->precision)
			*--s = '0';
	if (num)
	*--s = '-';

	if  (!params->minus_flag)
	return (print_number_right_shift(s, params));
	else
	return (print_number_left_shift(s, params));
}
/**
 * print_number_right_shift - print_number right shift
 * @s: string
 * @params: param
 * Return: int
 */
int print_number_right_shift(char *s, params_t *params)
{
unsigned int n = 0, n1, n2, i = _strlen(s);
char padchar = ' ';

if (params->zero_flag && !params->minus_flag)
	padchar = '0';
n1 = n2 = (!params->unsign && *s == '-');
		if (n1 && i < params->width && padchar == '0' && !params->minus_flag)
			s++;
		else
			n1 = 0;
		if ((params->plus_flag && !n2) ||
		(!params->plus_flag && params->space_flag && !n2))
			i++;
		if (n1 && padchar == '0')
			n += _putchar('-');
		if (params->plus_flag && !n2 && padchar == '0' && !params->unsign)
			n += _putchar('+');
		else if (!params->plus_flag && params->space_flag && !n2 &&
			!params->unsign && params->zero_flag)
			n += _putchar(' ');
		while (i++ < params->width)
			n += _putchar(padchar);
		if (n1 && padchar == ' ')
			n += _putchar('-');
		if (params->plus_flag && !n2 && padchar == ' ' && !params->unsign)
			n += _putchar('+');
		else if (!params->plus_flag && params->space_flag && !n2 &&
				!params->unsign && !params->zero_flag)
			n += _putchar(' ');
		n += _puts(s);
		return (n);
}
/**
 * print_number_left_shift - print_number_right_shift
 * @s: string
 * @params: arg
 * Return: int
 */
int print_number_left_shift(char *s, params_t *params)
{
	unsigned int n = 0, n1, n2, i = _strlen(s);
	char padchar = ' ';

	if (params->zero_flag && !params->minus_flag)
		padchar = '0';
	n1 = n2 = (!params->unsign && *s == ' ');
	if (n1 && i < params->width && padchar == '0' && !params->minus_flag)
		s++;
	else
		n1 = 0;

	if (params->plus_flag && !n2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !n2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(s);
	while (i++ < params->width)
		n += _putchar(padchar);
	return (n);
}

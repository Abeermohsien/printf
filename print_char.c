#include "main.h"
/**
 * print_char - prints char
 * @ap: char
 * @params: char
 * Return: int
 *
 */
int print_char(va_list ap, params_t *params)
{
	char padchar = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(padchar);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}
/**
 * print_int - prints char
 * @ap: char
 * @params: char
 * Return: int
 *
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);

	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}
/**
 * print_string - prints char
 * @ap: char
 * @params: char
 * Return: int
 *
 */
int print_string(va_list ap, params_t *params)
{
	char *s = va_arg(ap, char *), padchar = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!s))
	case 1:
		s = NULL_STRING;

	j = pad = _strlen(s);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
	if (params->precision != UINT_MAX)
		for (i = 0; i < pad; i++)
			sum += _putchar(*s++);
	else
		sum += _puts(s);
	}
	while (j++ < params->width)
		sum += _putchar(padchar);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*s++);
		else
			sum += _puts(s);
	}
	return (sum);
}
/**
 * print_percent - prints char
 * @ap: char
 * @params: char
 * Return: int
 *
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}
/**
 * print_S - prints char
 * @ap: char
 * @params: char
 * Return: int
 *
 */
int print_S(va_list ap, params_t *params)
{
	char *s = va_arg(ap, char *);
	char *hexa;
	int sum = 0;

	if ((int)(!s))
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('%');
			hexa = convert(*s, 16, 0, params);
			if (!hexa[1])
				sum += _putchar('\0');
			sum += _puts(hexa);
		}
		else
		{
			sum += _putchar(*s);
		}
	}
	return (sum);
}

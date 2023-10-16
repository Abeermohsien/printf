#include "main.h"
/**
 * convert -  convert fun
 * @n: number
 * @b: base
 * @f: flags
 * @params: paramters
 * Rturn: char
 */
char *convert(long int n, int b, int f, params_t *p)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long num = n;
	(void)params;
	
	if (!(flags & CONVERT_UNSIGNED) && n < 0)
	{
		num = - n;
		sign = '-';
	
	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[98];
	*ptr = '\0';
	
	do {
		*--ptr = arr[num % b];
		n /= b;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * print_unsigned - prints un signed
 * @ap: argumaent
 * @params: int
 * Retuen: int
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else
		l = (unsigned long)va_arg(ap, unsigned long);
	params->unsign = 1;
	return (print_number(convert(1, 10, CONVERT_UNSIGNED, params), params));
}
/**
 * print_address - prints address
 * @ap: char
 * @params: char
 * Return: int
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)");

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}

#include "main.h"
/**
 * print_from_to - print from to
 * @start: start point
 * @stop: ending point
 * @except: char
 * Return:int
 */
int print_from_to(char *start, char *stop, char *except)
{
	int s = 0;

	while (start <= stop)
	{
		if (start != except)
			s += _putchar(*start);
		start++;
	}
	return (s);
}
/**
 * print_rev  - prints in reverse
 * @ap: char
 * @params: char
 *
 * Return: int
 */
int print_rev(va_list ap, params_t *params)
{
	int length, s = 0;
	char *sr = va_arg(ap, char *);
	(void)params;

	if (sr)
	{
		for (length = 0; *sr; sr++)
			length++;
		sr--;
		for (; length > 0; sr--)
			s += _putchar(*sr);
	}
	return (s);
}
/**
 * print_rot13  - prints in reverse
 * @ap: char
 * @params: char
 *
 * Return: int
 *
 */
int print_rot13(va_list ap, params_t *params)
{
	int i, in;
	int counter = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM        nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	in = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			in = a[i] - 65;
			counter += _putchar(arr[in]);
		}
		else
			counter += _putchar(a[i]);
		i++;
	}
	return (counter);
}

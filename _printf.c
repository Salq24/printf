#include "main.h"

/**
 * _printf - produces output
 * according to a format
 * @format: character string
 * Return: num of xters printed,
 * excluding the null byte
 */

int _printf(const char *format, ...)

{
	int prnt = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
		format++;
		if (*format == 'c')
		{
			_putchar(va_arg(arg_list, int));
			prnt++;
		}
		else if (*format == 's')
			{
				char *s = va_arg(arg_list, char*);
				int len_of_s = 0;

				while (s[len_of_s] != '\0')
					len_of_s++;

				write(1, s, len_of_s);
				prnt += len_of_s;
			}
		}
		format++;
	}
	va_end(arg_list);

	return (prnt);
}

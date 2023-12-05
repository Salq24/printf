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
		if (*format != '%')
		{
			write(1, format, 1);
		}
		format++;
	}
		else
		{
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
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
			else if (*format == 'c')
			{
				_putchar( va_arg(arg_list, int));
				prnt++;
			}
		}
		format++;
	}
	va_end(arg_list);

	return (prnt);
}

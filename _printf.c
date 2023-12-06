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
	va_start(arg_list, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%' && (++format))
		{
		if (*format == 'c')
		{
		       	_putchar((char)(va_arg(arg_list, int));
			prnt++;
		}
		else if (*format == 's')
		{
		char *s = va_arg(arg_list, char*);
		while (s[len_of_s] != '\0')
		{
		_putchar(*s++);
		prnt++;
		}
		}
		else if (*format == '%')
		{
			_putchar('%');
			prnt++;

		}
		else
		{
	       _putchar(*format);	       
		prnt++;
		}
		format++;
	}
	va_end(arg_list);

	return (prnt);
}

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

	while (*format)
	{
		if (*format == '%' && (++format))
		{
			switch (*format)
			{
				case 'c':
		       	_putchar((char)va_arg(arg_list, int));
			prnt++;
			break;
			case 's':
			{
			char *s = va_arg(arg_list, char*);
			while (*s)
			{
			_putchar(*s++);
			prnt++;
			}
			break;
			}
			case '%':
			_putchar('%');
			prnt++;
			break;
			default:
			break;
			}
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

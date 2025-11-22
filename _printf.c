#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j, count = 0;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"S", print_S},
		{"d", print_dec},
		{"i", print_int},
		{NULL, NULL}
	};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				count++;
				i += 2;
				continue;
			}
			j = 0;
			while (p[j].type_arg)
			{
				if (format[i + 1] == *p[j].type_arg)
				{
					count += p[j].f(args);
					i += 2;
					break;
				}
				j++;
			}
			if (!p[j].type_arg)
			{
				_putchar('%');
				count++;
				i++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}

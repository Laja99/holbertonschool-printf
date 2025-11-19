#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
* _printf - function that produces output according to a format
* @format: format string containing format spesifiers
* Return: number of digit printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0; /* for return number of byte printed*/

	if (!format) /*if format NULL */
	{
		return (-1);
	}

	va_start(args, format);
	while (*format)
	{
		if (*format == '%') /* if we find % look to next letter*/
		{
			++format;
			if (!*format)
				return (-1);
			else if (*format == 'c')
				count += _putchar(va_arg(args, int));
			else if (*format == 's')
				count += print_string(va_arg(args, char*));
			else if (*format == '%')
				count += _putchar('%'); /* or count += _putchar(*format) */
			else
			{
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
		else /*Print the character next to '%' if it hasn't in the code */
		{
			count += _putchar(*format);
		}
		++format;
	}
	count += _putchar('\n');
	va_end(args);
	return (count);
}

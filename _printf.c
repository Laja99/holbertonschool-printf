#include "main.h"

int _printf(const char *format, ...)
{
	unsigned int i = 0, ibuf = 0;
	int j, count = 0, flags, size;
	char buffer[1024];
	va_list args;
	print_t p[] = {
		{"c", print_c}, {"s", print_s}, {"d", print_dec},
		{"i", print_int}, {"b", print_b}, {"u", print_u},
		{"o", print_o}, {"x", print_x}, {"X", print_X},
		{"p", print_p}, {NULL, NULL}
	};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			flags = get_flags(format, (int *)&i);
			size = get_size(format, (int *)&i);
			
			if (format[i + 1] == '%')
			{
				handl_buf(buffer, '%', &ibuf);
				count++;
				i += 2;
				continue;
			}
			for (j = 0; p[j].type_arg; j++)
			{
				if (format[i + 1] == *p[j].type_arg)
				{
					count += p[j].f(args, buffer, &ibuf, flags, size);
					i += 2;
					break;
				}
			}
			if (!p[j].type_arg)
			{
				handl_buf(buffer, '%', &ibuf);
				count++;
				i++;
			}
		}
		else
		{
			handl_buf(buffer, format[i], &ibuf);
			count++;
			i++;
		}
	}
	write(1, buffer, ibuf);
	va_end(args);
	return (count);
}

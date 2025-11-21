#include "main.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print_c(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

int print_s(va_list args)
{
	int i = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

int print_i(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;
	unsigned int temp;
	int div = 1;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	temp = num;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}

	while (div != 0)
	{
		_putchar((num / div) % 10 + '0');
		count++;
		div /= 10;
	}
	return (count);
}

int print_d(va_list args)
{
	return (print_i(args));
}

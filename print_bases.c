#include "main.h"

int print_u(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int num, temp;
	int count = 0;
	unsigned int div = 1;

	num = n;
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

int print_o(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int num, temp;
	int count = 0;
	unsigned int div = 1;

	num = n;
	temp = num;
	while (temp > 7)
	{
		div *= 8;
		temp /= 8;
	}
	while (div != 0)
	{
		_putchar((num / div) % 8 + '0');
		count++;
		div /= 8;
	}
	return (count);
}

int print_x(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int num, temp;
	int count = 0;
	unsigned int div = 1;

	num = n;
	temp = num;
	while (temp > 15)
	{
		div *= 16;
		temp /= 16;
	}
	while (div != 0)
	{
		if ((num / div) % 16 < 10)
			_putchar((num / div) % 16 + '0');
		else
			_putchar((num / div) % 16 - 10 + 'a');
		count++;
		div /= 16;
	}
	return (count);
}

int print_X(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int num, temp;
	int count = 0;
	unsigned int div = 1;

	num = n;
	temp = num;
	while (temp > 15)
	{
		div *= 16;
		temp /= 16;
	}
	while (div != 0)
	{
		if ((num / div) % 16 < 10)
			_putchar((num / div) % 16 + '0');
		else
			_putchar((num / div) % 16 - 10 + 'A');
		count++;
		div /= 16;
	}
	return (count);
}

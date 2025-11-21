#include "main.h"
#include <limits.h>

int print_int(va_list args)
{
	int n = va_arg(args, int);
	unsigned int num;
	unsigned int div = 1, temp;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = (unsigned int)(-(long)n);
	}
	else
		num = (unsigned int)n;

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

int print_dec(va_list args)
{
	return (print_int(args));
}

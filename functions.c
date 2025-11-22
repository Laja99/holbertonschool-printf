#include "main.h"

int print_c(va_list args, char *buf, unsigned int *ibuf, int flags, int size)
{
	char c = va_arg(args, int);
	(void)flags;
	(void)size;
	handl_buf(buf, c, ibuf);
	return (1);
}

int print_s(va_list args, char *buf, unsigned int *ibuf, int flags, int size)
{
	int i = 0;
	char *str = va_arg(args, char *);
	(void)flags;
	(void)size;

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		handl_buf(buf, str[i], ibuf);
		i++;
	}
	return (i);
}

int print_int(va_list args, char *buf, unsigned int *ibuf, int flags, int size)
{
	long int n;
	unsigned long int num, temp, div = 1;
	int count = 0;

	if (size == S_LONG)
		n = va_arg(args, long int);
	else if (size == S_SHORT)
		n = (short)va_arg(args, int);
	else
		n = (int)va_arg(args, int);

	if (n >= 0)
	{
		if (flags & F_PLUS)
		{
			handl_buf(buf, '+', ibuf);
			count++;
		}
		else if (flags & F_SPACE)
		{
			handl_buf(buf, ' ', ibuf);
			count++;
		}
		num = n;
	}
	else
	{
		handl_buf(buf, '-', ibuf);
		count++;
		num = (unsigned long int)((-1) * n);
	}
	
	temp = num;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	while (div != 0)
	{
		handl_buf(buf, (num / div) % 10 + '0', ibuf);
		count++;
		div /= 10;
	}
	return (count);
}

int print_dec(va_list args, char *buf, unsigned int *ibuf, int flags, int size)
{
	return (print_int(args, buf, ibuf, flags, size));
}

#include "main.h"

int print_c(va_list args, char *buf, unsigned int *ibuf)
{
	char c = va_arg(args, int);
	handl_buf(buf, c, ibuf);
	return (1);
}

int print_s(va_list args, char *buf, unsigned int *ibuf)
{
	int i = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		handl_buf(buf, str[i], ibuf);
		i++;
	}
	return (i);
}

int print_int(va_list args, char *buf, unsigned int *ibuf)
{
	int n = va_arg(args, int);
	unsigned int num, temp, div = 1;
	int count = 0;

	if (n < 0)
	{
		handl_buf(buf, '-', ibuf);
		count++;
		num = -n;
	}
	else
		num = n;
	
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

int print_dec(va_list args, char *buf, unsigned int *ibuf)
{
	return (print_int(args, buf, ibuf));
}

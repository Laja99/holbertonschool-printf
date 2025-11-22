#include "main.h"

int print_b(va_list args, char *buf, unsigned int *ibuf)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int m = 2147483648, i, sum = 0;
	unsigned int a[32];
	int count = 0;

	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			handl_buf(buf, '0' + a[i], ibuf);
			count++;
		}
	}
	return (count);
}

int print_u(va_list args, char *buf, unsigned int *ibuf)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int temp, div = 1;
	int count = 0;

	temp = n;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	while (div != 0)
	{
		handl_buf(buf, (n / div) % 10 + '0', ibuf);
		count++;
		div /= 10;
	}
	return (count);
}

int print_o(va_list args, char *buf, unsigned int *ibuf)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int temp, div = 1;
	int count = 0;

	temp = n;
	while (temp > 7)
	{
		div *= 8;
		temp /= 8;
	}
	while (div != 0)
	{
		handl_buf(buf, (n / div) % 8 + '0', ibuf);
		count++;
		div /= 8;
	}
	return (count);
}

int print_x(va_list args, char *buf, unsigned int *ibuf)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int temp, div = 1;
	int count = 0;

	temp = n;
	while (temp > 15)
	{
		div *= 16;
		temp /= 16;
	}
	while (div != 0)
	{
		if ((n / div) % 16 < 10)
			handl_buf(buf, (n / div) % 16 + '0', ibuf);
		else
			handl_buf(buf, (n / div) % 16 - 10 + 'a', ibuf);
		count++;
		div /= 16;
	}
	return (count);
}

int print_X(va_list args, char *buf, unsigned int *ibuf)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int temp, div = 1;
	int count = 0;

	temp = n;
	while (temp > 15)
	{
		div *= 16;
		temp /= 16;
	}
	while (div != 0)
	{
		if ((n / div) % 16 < 10)
			handl_buf(buf, (n / div) % 16 + '0', ibuf);
		else
			handl_buf(buf, (n / div) % 16 - 10 + 'A', ibuf);
		count++;
		div /= 16;
	}
	return (count);
}

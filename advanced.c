#include "main.h"

int print_b(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int m = 2147483648, i, sum = 0;
	unsigned int a[32];
	int count = 0;
	(void)flags; (void)width; (void)size; (void)precision;

	a[0] = n / m;
	for (i = 1; i < 32; i++) { m /= 2; a[i] = (n / m) % 2; }
	for (i = 0; i < 32; i++) {
		sum += a[i];
		if (sum || i == 31) { handl_buf(buf, '0' + a[i], ibuf); count++; }
	}
	return (count);
}

int print_u(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
	unsigned long int n, temp, div = 1;
	int count = 0, digits = 1, padd = 0;
	char pad = ' ';

	if (size == S_LONG)
		n = va_arg(args, unsigned long int);
	else if (size == S_SHORT)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = (unsigned int)va_arg(args, unsigned int);

	if (n == 0 && precision == 0)
	{
		while (width > 0) { handl_buf(buf, ' ', ibuf); width--; count++; }
		return (count);
	}

	temp = n; digits = 0; while (temp != 0) { digits++; temp /= 10; }
	if (digits == 0) digits = 1;

	if (precision > digits) padd = precision - digits;
	if ((flags & F_ZERO) && !(flags & F_MINUS) && precision == -1) pad = '0';

	{
		int prefix = 0;
		int total = prefix + digits + padd;

		if (!(flags & F_MINUS))
		{
			if (pad == '0')
			{
				while (width > total) { handl_buf(buf, '0', ibuf); width--; count++; }
			}
			else
			{
				while (width > total) { handl_buf(buf, ' ', ibuf); width--; count++; }
			}
		}

		while (padd > 0) { handl_buf(buf, '0', ibuf); padd--; count++; }

		div = 1; temp = n; while (temp > 9) { div *= 10; temp /= 10; }
		while (div != 0) { handl_buf(buf, (n / div) % 10 + '0', ibuf); div /= 10; count++; }

		while (width > total) { handl_buf(buf, ' ', ibuf); width--; count++; }
	}
	return (count);
}

int print_o(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
	unsigned long int n, temp, div = 1;
	int count = 0, digits = 1, padd = 0;
	char pad = ' ';

	if (size == S_LONG)
		n = va_arg(args, unsigned long int);
	else if (size == S_SHORT)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = (unsigned int)va_arg(args, unsigned int);

	if (n == 0 && precision == 0 && !(flags & F_HASH))
	{
		while (width > 0) { handl_buf(buf, ' ', ibuf); width--; count++; }
		return (count);
	}

	temp = n; digits = 0; while (temp != 0) { digits++; temp /= 8; }
	if (digits == 0) digits = 1;

	if (precision > digits) padd = precision - digits;
	if ((flags & F_ZERO) && !(flags & F_MINUS) && precision == -1) pad = '0';

	{
		int prefix = (flags & F_HASH && n != 0) ? 1 : 0;
		int total = prefix + digits + padd;

		if (!(flags & F_MINUS))
		{
			if (pad == '0')
			{
				if (prefix) { handl_buf(buf, '0', ibuf); count++; }
				while (width > total) { handl_buf(buf, '0', ibuf); width--; count++; }
			}
			else
			{
				while (width > total) { handl_buf(buf, ' ', ibuf); width--; count++; }
				if (prefix) { handl_buf(buf, '0', ibuf); count++; }
			}
		}
		else
		{
			if (prefix) { handl_buf(buf, '0', ibuf); count++; }
		}

		while (padd > 0) { handl_buf(buf, '0', ibuf); padd--; count++; }

		div = 1; temp = n; while (temp > 7) { div *= 8; temp /= 8; }
		while (div != 0) { handl_buf(buf, (n / div) % 8 + '0', ibuf); div /= 8; count++; }

		while (width > total) { handl_buf(buf, ' ', ibuf); width--; count++; }
	}
	return (count);
}


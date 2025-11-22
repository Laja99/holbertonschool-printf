#include "main.h"

int print_c(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);
	int count = 0;
	(void)precision; (void)size;

	if (!(flags & F_MINUS))
		while (width > 1) { handl_buf(buf, ' ', ibuf); width--; count++; }
	
	handl_buf(buf, c, ibuf); count++;
	
	while (width > 1) { handl_buf(buf, ' ', ibuf); width--; count++; }
	return (count);
}

int print_s(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
	int i = 0, len = 0, count = 0;
	char *str = va_arg(args, char *);
	(void)size;

	if (str == NULL) str = "(null)";
	while (str[len]) len++;
	
	if (precision >= 0 && precision < len) len = precision;

	if (!(flags & F_MINUS))
		while (width > len) { handl_buf(buf, ' ', ibuf); width--; count++; }
	
	while (i < len) { handl_buf(buf, str[i], ibuf); i++; count++; }

	while (width > len) { handl_buf(buf, ' ', ibuf); width--; count++; }
	return (count);
}

int print_int(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
	long int n;
	unsigned long int num, temp, div = 1;
	int count = 0, len = 0, neg = 0, padd = 0;
	char pad = ' ';

	if (size == S_LONG) n = va_arg(args, long int);
	else if (size == S_SHORT) n = (short)va_arg(args, int);
	else n = (int)va_arg(args, int);

	if (n == 0 && precision == 0) {
		if (width > 0 && (flags & F_PLUS)) { handl_buf(buf, '+', ibuf); count++; width--; }
		else if (width > 0 && (flags & F_SPACE)) { handl_buf(buf, ' ', ibuf); count++; width--; }
		while (width > 0) { handl_buf(buf, ' ', ibuf); width--; count++; }
		return (count);
	}
	if (n < 0) { neg = 1; num = (unsigned long int)((-1) * n); len++; }
	else { num = n; if ((flags & F_PLUS) || (flags & F_SPACE)) len++; }
	
	temp = num;
	while (temp > 9) { div *= 10; temp /= 10; len++; }
	len++;

	if (precision > (neg ? len - 1 : len)) padd = precision - (neg ? len - 1 : len);
	if (flags & F_ZERO && !(flags & F_MINUS) && precision == -1) pad = '0';
	
	if (!(flags & F_MINUS))
		while (width > len + padd) { handl_buf(buf, pad, ibuf); width--; count++; }
	
	if (neg) handl_buf(buf, '-', ibuf);
	else if (flags & F_PLUS) handl_buf(buf, '+', ibuf);
	else if (flags & F_SPACE) handl_buf(buf, ' ', ibuf);

	while (padd > 0) { handl_buf(buf, '0', ibuf); padd--; }
	
	div = 1; temp = num;
	while (temp > 9) { div *= 10; temp /= 10; }
	while (div != 0) { handl_buf(buf, (num / div) % 10 + '0', ibuf); div /= 10; }
	count += len;
	
	while (width > len) { handl_buf(buf, ' ', ibuf); width--; count++; }
	return (count);
}

int print_dec(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
	return (print_int(args, buf, ibuf, flags, width, precision, size));
}

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
	int count = 0, len = 1, padd = 0;
	char pad = ' ';

	if (size == S_LONG) n = va_arg(args, unsigned long int);
	else if (size == S_SHORT) n = (unsigned short)va_arg(args, unsigned int);
	else n = (unsigned int)va_arg(args, unsigned int);

	if (n == 0 && precision == 0) {
		while (width > 0) { handl_buf(buf, ' ', ibuf); width--; count++; }
		return (count);
	}
	temp = n;
	while (temp > 9) { div *= 10; temp /= 10; len++; }

	if (precision > len) padd = precision - len;
	if (flags & F_ZERO && !(flags & F_MINUS) && precision == -1) pad = '0';

	if (!(flags & F_MINUS))
		while (width > len + padd) { handl_buf(buf, pad, ibuf); width--; count++; }
	
	while (padd > 0) { handl_buf(buf, '0', ibuf); padd--; }
	while (div != 0) { handl_buf(buf, (n / div) % 10 + '0', ibuf); count++; div /= 10; }
	while (width > len) { handl_buf(buf, ' ', ibuf); width--; count++; }
	return (count);
}

int print_o(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
	unsigned long int n, temp, div = 1;
	int count = 0, len = 1, padd = 0;
	char pad = ' ';

	if (size == S_LONG) n = va_arg(args, unsigned long int);
	else if (size == S_SHORT) n = (unsigned short)va_arg(args, unsigned int);
	else n = (unsigned int)va_arg(args, unsigned int);

	if (n == 0 && precision == 0 && !(flags & F_HASH)) {
		while (width > 0) { handl_buf(buf, ' ', ibuf); width--; count++; }
		return (count);
	}
	temp = n;
	while (temp > 7) { div *= 8; temp /= 8; len++; }
	if (flags & F_HASH && n != 0) len++;
	if (precision > len) padd = precision - len;
	if (flags & F_ZERO && !(flags & F_MINUS) && precision == -1) pad = '0';

	if (!(flags & F_MINUS))
		while (width > len + padd) { handl_buf(buf, pad, ibuf); width--; count++; }
	
	if ((flags & F_HASH) && n != 0) handl_buf(buf, '0', ibuf);
	while (padd > 0) { handl_buf(buf, '0', ibuf); padd--; }
	
	while (div != 0) { handl_buf(buf, (n / div) % 8 + '0', ibuf); count++; div /= 8; }
	while (width > len) { handl_buf(buf, ' ', ibuf); width--; count++; }
	return (count);
}

int print_x(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
	unsigned long int n, temp, div = 1;
	int count = 0, len = 1, padd = 0;
	char pad = ' ';

	if (size == S_LONG) n = va_arg(args, unsigned long int);
	else if (size == S_SHORT) n = (unsigned short)va_arg(args, unsigned int);
	else n = (unsigned int)va_arg(args, unsigned int);

	if (n == 0 && precision == 0) {
		while (width > 0) { handl_buf(buf, ' ', ibuf); width--; count++; }
		return (count);
	}
	temp = n;
	while (temp > 15) { div *= 16; temp /= 16; len++; }
	if (flags & F_HASH && n != 0) len += 2;
	if (precision > len) padd = precision - len;
	if (flags & F_ZERO && !(flags & F_MINUS) && precision == -1) pad = '0';

	if (!(flags & F_MINUS))
		while (width > len + padd) { handl_buf(buf, pad, ibuf); width--; count++; }

	if ((flags & F_HASH) && n != 0) { handl_buf(buf, '0', ibuf); handl_buf(buf, 'x', ibuf); }
	while (padd > 0) { handl_buf(buf, '0', ibuf); padd--; }
	
	while (div != 0) {
		if ((n / div) % 16 < 10) handl_buf(buf, (n / div) % 16 + '0', ibuf);
		else handl_buf(buf, (n / div) % 16 - 10 + 'a', ibuf);
		count++; div /= 16;
	}
	while (width > len) { handl_buf(buf, ' ', ibuf); width--; count++; }
	return (count);
}

int print_X(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
	unsigned long int n, temp, div = 1;
	int count = 0, len = 1, padd = 0;
	char pad = ' ';

	if (size == S_LONG) n = va_arg(args, unsigned long int);
	else if (size == S_SHORT) n = (unsigned short)va_arg(args, unsigned int);
	else n = (unsigned int)va_arg(args, unsigned int);

	if (n == 0 && precision == 0) {
		while (width > 0) { handl_buf(buf, ' ', ibuf); width--; count++; }
		return (count);
	}
	temp = n;
	while (temp > 15) { div *= 16; temp /= 16; len++; }
	if (flags & F_HASH && n != 0) len += 2;
	if (precision > len) padd = precision - len;
	if (flags & F_ZERO && !(flags & F_MINUS) && precision == -1) pad = '0';

	if (!(flags & F_MINUS))
		while (width > len + padd) { handl_buf(buf, pad, ibuf); width--; count++; }

	if ((flags & F_HASH) && n != 0) { handl_buf(buf, '0', ibuf); handl_buf(buf, 'X', ibuf); }
	while (padd > 0) { handl_buf(buf, '0', ibuf); padd--; }
	
	while (div != 0) {
		if ((n / div) % 16 < 10) handl_buf(buf, (n / div) % 16 + '0', ibuf);
		else handl_buf(buf, (n / div) % 16 - 10 + 'A', ibuf);
		count++; div /= 16;
	}
	while (width > len) { handl_buf(buf, ' ', ibuf); width--; count++; }
	return (count);
}

int print_p(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
	void *add = va_arg(args, void *);
	unsigned long int n = (unsigned long int)add;
	unsigned long int m = 1, temp = n;
	int count = 0, len = 2;
	char *str = "(nil)";
	int i = 0;
	(void)flags; (void)size; (void)precision;

	if (add == NULL) {
		while (str[i]) len++;
		while (width > len) { handl_buf(buf, ' ', ibuf); width--; count++; }
		while (str[i]) { handl_buf(buf, str[i], ibuf); i++; count++; }
		while (width > len) { handl_buf(buf, ' ', ibuf); width--; count++; }
		return (count);
	}
	while (temp > 15) { m *= 16; temp /= 16; len++; }
	
	if (!(flags & F_MINUS))
		while (width > len) { handl_buf(buf, ' ', ibuf); width--; count++; }
	
	handl_buf(buf, '0', ibuf); handl_buf(buf, 'x', ibuf); count += 2;
	while (m > 0) {
		unsigned int digit = n / m;
		if (digit < 10) handl_buf(buf, digit + '0', ibuf);
		else handl_buf(buf, digit - 10 + 'a', ibuf);
		count++; n %= m; m /= 16;
	}
	while (width > len) { handl_buf(buf, ' ', ibuf); width--; count++; }
	return (count);
}

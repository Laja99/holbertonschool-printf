#include "main.h"
int print_c(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
int print_s(va_list args)
{
	int i = 0;
	char *str = va_arg(args, char *);
	if (!str) str = "(null)";
	while (str[i]) { _putchar(str[i]); i++; }
	return i;
}
int print_i(va_list args)
{
	int n = va_arg(args, int), count = 0;
	unsigned int num = n < 0 ? -n : n;
	if (n < 0) { _putchar('-'); count++; }
	unsigned int div = 1, temp = num;
	while (temp > 9) { div *= 10; temp /= 10; }
	while (div) { _putchar((num / div) % 10 + '0'); count++; div /= 10; }
	return count;
}
int print_d(va_list args) { return print_i(args); }
int _putchar(char c) { return write(1, &c, 1); }

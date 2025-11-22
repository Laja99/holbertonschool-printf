#include "main.h"
#include <stdio.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_c - prints a character
 * @args: arguments
 * Return: 1
 */
int print_c(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_s - prints a string
 * @args: arguments
 * Return: number of characters printed
 */
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

/**
 * print_int - prints an integer
 * @args: arguments
 * Return: number of characters printed
 */
int print_int(va_list args)
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

/**
 * print_dec - prints a decimal
 * @args: arguments
 * Return: number of characters printed
 */
int print_dec(va_list args)
{
	return (print_int(args));
}

/**
 * print_S - prints a string with non-printable chars in \xHH format
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_S(va_list args)
{
    char *str;
    int i, count = 0;
    char hex[3];

    str = va_arg(args, char *);
    if (str == NULL)
        str = "(null)";

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
        {
            count += _putchar('\\');
            count += _putchar('x');

            sprintf(hex, "%02X", (unsigned char)str[i]);

            count += _putchar(hex[0]);
            count += _putchar(hex[1]);
        }
        else
        {
            count += _putchar(str[i]);
        }
    }
    return (count);
}

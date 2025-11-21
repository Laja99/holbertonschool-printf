#include "main.h"

int _putchar(char c)
{
    return write(1, &c, 1);
}

int print_int(int n)
{
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        _putchar('-');
        count++;
        num = -n;
    }
    else
        num = n;

    if (num / 10)
        count += print_int(num / 10);

    _putchar('0' + (num % 10));
    count++;

    return count;
}

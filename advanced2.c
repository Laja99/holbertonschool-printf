#include "main.h"

int print_x(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size)
{
    unsigned long int n, temp, div = 1;
    int count = 0, len = 1, padd = 0;
    char pad = ' ';

    if (size == S_LONG) n = va_arg(args, unsigned long int);
    else if (size == S_SHORT) n = (unsigned short)va_arg(args, unsigned int);
    else n = (unsigned int)va_arg(args, unsigned int);

    if (n == 0 && precision == 0)
    {
        while (width > 0)
        {
            handl_buf(buf, ' ', ibuf);
            width--;
            count++;
        }
        return (count);
    }
    temp = n; len = 0; while (temp != 0) { len++; temp /= 16; }
    if (len == 0) len = 1;

    if (precision > len) padd = precision - len;
    if ((flags & F_ZERO) && !(flags & F_MINUS) && precision == -1) pad = '0';

    {
        int prefix = (flags & F_HASH && n != 0) ? 2 : 0;
        int total = prefix + len + padd;

        if (!(flags & F_MINUS))
        {
            if (pad == '0')
            {
                if (prefix)
                {
                    handl_buf(buf, '0', ibuf); handl_buf(buf, 'x', ibuf); count += 2;
                }
                while (width > total) { handl_buf(buf, '0', ibuf); width--; count++; }
            }
            else
            {
                while (width > total) { handl_buf(buf, ' ', ibuf); width--; count++; }
                if (prefix) { handl_buf(buf, '0', ibuf); handl_buf(buf, 'x', ibuf); count += 2; }
            }
        }
        else
        {
            if (prefix) { handl_buf(buf, '0', ibuf); handl_buf(buf, 'x', ibuf); count += 2; }
        }

        while (padd > 0) { handl_buf(buf, '0', ibuf); padd--; count++; }

        div = 1; temp = n; while (temp > 15) { div *= 16; temp /= 16; }
        while (div != 0)
        {
            if ((n / div) % 16 < 10)
                handl_buf(buf, (n / div) % 16 + '0', ibuf);
            else
                handl_buf(buf, (n / div) % 16 - 10 + 'a', ibuf);
            count++;
            div /= 16;
        }
        while (width > total) { handl_buf(buf, ' ', ibuf); width--; count++; }
    }
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

    if (n == 0 && precision == 0)
    {
        while (width > 0)
        {
            handl_buf(buf, ' ', ibuf);
            width--;
            count++;
        }
        return (count);
    }
    temp = n; len = 0; while (temp != 0) { len++; temp /= 16; }
    if (len == 0) len = 1;

    if (precision > len) padd = precision - len;
    if ((flags & F_ZERO) && !(flags & F_MINUS) && precision == -1) pad = '0';

    {
        int prefix = (flags & F_HASH && n != 0) ? 2 : 0;
        int total = prefix + len + padd;

        if (!(flags & F_MINUS))
        {
            if (pad == '0')
            {
                if (prefix)
                {
                    handl_buf(buf, '0', ibuf); handl_buf(buf, 'X', ibuf); count += 2;
                }
                while (width > total) { handl_buf(buf, '0', ibuf); width--; count++; }
            }
            else
            {
                while (width > total) { handl_buf(buf, ' ', ibuf); width--; count++; }
                if (prefix) { handl_buf(buf, '0', ibuf); handl_buf(buf, 'X', ibuf); count += 2; }
            }
        }
        else
        {
            if (prefix) { handl_buf(buf, '0', ibuf); handl_buf(buf, 'X', ibuf); count += 2; }
        }

        while (padd > 0) { handl_buf(buf, '0', ibuf); padd--; count++; }

        div = 1; temp = n; while (temp > 15) { div *= 16; temp /= 16; }
        while (div != 0)
        {
            if ((n / div) % 16 < 10)
                handl_buf(buf, (n / div) % 16 + '0', ibuf);
            else
                handl_buf(buf, (n / div) % 16 - 10 + 'A', ibuf);
            count++;
            div /= 16;
        }
        while (width > total) { handl_buf(buf, ' ', ibuf); width--; count++; }
    }
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
    (void)flags;
    (void)size;
    (void)precision;

    if (add == NULL)
    {
        while (str[i])
            len++;
        while (width > len)
        {
            handl_buf(buf, ' ', ibuf);
            width--;
            count++;
        }
        while (str[i])
        {
            handl_buf(buf, str[i], ibuf);
            i++;
            count++;
        }
        while (width > len)
        {
            handl_buf(buf, ' ', ibuf);
            width--;
            count++;
        }
        return (count);
    }
    while (temp > 15)
    {
        m *= 16;
        temp /= 16;
        len++;
    }

    if (!(flags & F_MINUS))
        while (width > len)
        {
            handl_buf(buf, ' ', ibuf);
            width--;
            count++;
        }

    handl_buf(buf, '0', ibuf);
    handl_buf(buf, 'x', ibuf);
    count += 2;
    while (m > 0)
    {
        unsigned int digit = n / m;
        if (digit < 10)
            handl_buf(buf, digit + '0', ibuf);
        else
            handl_buf(buf, digit - 10 + 'a', ibuf);
        count++;
        n %= m;
        m /= 16;
    }
    while (width > len)
    {
        handl_buf(buf, ' ', ibuf);
        width--;
        count++;
    }
    return (count);
}

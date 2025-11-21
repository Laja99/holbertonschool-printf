#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_int(int n)
{
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = -n;
    }
    else
        num = n;

    if (num / 10)
        count += print_int(num / 10);

    count += write(1, &"0123456789"[num % 10], 1);

    return count;
}

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *p;

    va_start(args, format);

    for (p = format; *p; p++)
    {
        if (*p != '%')
        {
            write(1, p, 1);
            count++;
            continue;
        }
        p++;
        switch (*p)
        {
            case 'c':
                count += write(1, (char[]){(char)va_arg(args,int),0}, 1);
                break;
            case 's':
                {
                    char *str = va_arg(args, char*);
                    while (*str)
                    {
                        write(1, str, 1);
                        str++;
                        count++;
                    }
                }
                break;
            case '%':
                write(1, "%", 1);
                count++;
                break;
            case 'd':
            case 'i':
                count += print_int(va_arg(args, int));
                break;
            default:
                write(1, "%", 1);
                write(1, p, 1);
                count += 2;
                break;
        }
    }

    va_end(args);
    return count;
}

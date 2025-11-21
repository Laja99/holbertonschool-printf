#include "main.h"
#include <stdarg.h>

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
            _putchar(*p);
            count++;
            continue;
        }
        p++;
        switch (*p)
        {
            case 'c':
            {
                char c = (char)va_arg(args, int);
                count += _putchar(c);
            }
            break;
            case 's':
            {
                char *str = va_arg(args, char*);
                while (*str)
                {
                    _putchar(*str);
                    str++;
                    count++;
                }
            }
            break;
            case '%':
                _putchar('%');
                count++;
                break;
            case 'd':
            case 'i':
                count += print_int(va_arg(args, int));
                break;
            default:
                _putchar('%');
                _putchar(*p);
                count += 2;
                break;
        }
    }

    va_end(args);
    return count;
}

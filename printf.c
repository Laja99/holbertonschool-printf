#include "main.h"
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0; /* for return number of byte printed*/

    if (!format || format[0] == '%' || format[1] == '\0') /*if format NULL or % in program name */
    {
        return (-1);
    }

    va_start (args, format); 
    while (format[i])
    {
        if (format[i] == '%') /* if we find % look to anther letter*/
        {
	        i++;
	        if (format[i] == '\0')
            {
	        	return (-1);
	        }
            else if (format[i] == 'c')
            {
                count += _putchar(va_arg(args, int));
            }
            else if (format[i] == 's')
            {
                count += print_string(va_arg(args, char*));
            }
            else if (format[i] == '%')
            {
                count += _putchar('%');
            }
        }else
        {
            count += _putchar(format[i]);
            i++;
        }
    
    }
    
    va_end(args);
    _putchar('\n');
    return (count);
}

#include "main.h"
/**
 * print_R - Prints a string encoded in ROT13
 * @args: The va_list containing the string argument
 * @buf: The buffer to write characters to
 * @ibuf: Pointer to the current index in the buffer
 * @flags: Flags (not used)
 * @width: Width (not used)
 * @precision: Maximum number of characters to print (-1 for all)
 * @size: Size modifier (not used)
 *
 * Return: Number of characters printed
 */
int print_R(va_list args, char *buf, unsigned int *ibuf,
            int flags, int width, int precision, int size)
{
    char *str = va_arg(args, char *);
    int len = 0, count = 0;
    (void)flags; (void)width; (void)precision; (void)size;

    if (!str) str = "(null)";

    while (str[len]) len++;
    if (precision >= 0 && precision < len) len = precision;

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') c = ((c - 'A' + 13) % 26) + 'A';
        else if (c >= 'a' && c <= 'z') c = ((c - 'a' + 13) % 26) + 'a';
        count += handl_buf(buf, c, ibuf);
    }

    return count;
}



#include "main.h"
int _putchar(char c)
{
    return (write(1, &c, 1));
}
int print_string(char *str)
{
    return (write(1, &str, 1));
}
int print_number(int n)
{
    return (write(1, &n, 1));
}
#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);  // Function that prints formatted output, replacing % with corresponding arguments
int _putchar(char c); // %c
int print_string(char *str); // %s
int print_number(int n); // %d or %i

int print_unsigned(unsigned int n);
int _octal(unsigned int n); // %o
int _hexadecimal(unsigned int n, int uppercase); // %X or %x 

#endif
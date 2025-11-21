#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct print
{
	char *type_arg;
	int (*f)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_int(va_list args);
int print_dec(va_list args);

#endif

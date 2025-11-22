#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define F_PLUS 1
#define F_SPACE 2
#define F_HASH 4
#define F_ZERO 8
#define F_MINUS 16

#define S_LONG 1
#define S_SHORT 2

typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int *, int, int, int, int);
} print_t;

int _printf(const char *format, ...);
int handl_buf(char *buf, char c, unsigned int *ibuf);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int print_c(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size);
int print_s(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size);
int print_int(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size);
int print_dec(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size);
int print_b(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size);
int print_u(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size);
int print_o(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size);
int print_x(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size);
int print_X(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size);
int print_p(va_list args, char *buf, unsigned int *ibuf, int flags, int width, int precision, int size);

#endif

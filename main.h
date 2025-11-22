#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int *);
} print_t;

int _printf(const char *format, ...);
int handl_buf(char *buf, char c, unsigned int *ibuf);
int print_c(va_list args, char *buf, unsigned int *ibuf);
int print_s(va_list args, char *buf, unsigned int *ibuf);
int print_int(va_list args, char *buf, unsigned int *ibuf);
int print_dec(va_list args, char *buf, unsigned int *ibuf);
int print_b(va_list args, char *buf, unsigned int *ibuf);
int print_u(va_list args, char *buf, unsigned int *ibuf);
int print_o(va_list args, char *buf, unsigned int *ibuf);
int print_x(va_list args, char *buf, unsigned int *ibuf);
int print_X(va_list args, char *buf, unsigned int *ibuf);
int print_p(va_list args, char *buf, unsigned int *ibuf);

#endif

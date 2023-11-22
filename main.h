#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
char *intToString(int n);

typedef int (*format_func)(va_list *);
typedef struct format_map {
    char format;
    format_func func;
} format_map;

#endif /* MAIN_H */


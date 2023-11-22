#include "main.h"
#include <unistd.h>

int print_char(va_list *args);
int print_string(va_list *args);
int print_int(va_list *args);

int _putchar(char c) {
	return write(1, &c, 1);
}

int print_char(va_list *args) {
	char c = va_arg(*args, int);
	return _putchar(c);
}

int print_string(va_list *args) {
	char *str = va_arg(*args, char *);
	int count = 0;
	if (str == NULL) {
		str = "(null)";
	}
	while (*str) {
		_putchar(*str++);
		count++;
	}
	return count;
}

int print_int(va_list *args) {
	int n = va_arg(*args, int);
	char *str = intToString(n);
	char *p;
	int count = 0;
	for (p = str; *p; p++) {
		_putchar(*p);
		count++;
	}
	free(str);
	return count;
}

format_map fm[] = {
	{'c', print_char},
	{'s', print_string},
	{'d', print_int},
	{'i', print_int},
};

int _printf(const char *format, ...) {
	va_list args;
	int printed_chars = 0;
	size_t i;
	int found;

	va_start(args, format);
	while (*format) {
		if (*format != '%') {
			printed_chars += _putchar(*format);
		} else {
			format++;
			i = 0;
			found = 0;
			while (i < sizeof(fm) / sizeof(fm[0])) {
				if (fm[i].format == *format) {
					printed_chars += fm[i].func(&args);
					found = 1;
					break;
				}
				i++;
			}
			if (!found) {
				printed_chars += _putchar('%');
				printed_chars += _putchar(*format);
			}
		}
		format++;
	}
	va_end(args);
	return printed_chars;
}


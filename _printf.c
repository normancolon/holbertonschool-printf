#include "main.h"
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c)
{
    return (write(1, &c, 1));
}

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char *str_arg;
    char char_arg;
    int int_arg;
    char *int_str;
    char *p;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            _putchar(*format);
            printed_chars++;
        }
        else
        {
            format++;
            switch (*format)
            {
            case 'c':
                char_arg = va_arg(args, int);
                _putchar(char_arg);
                printed_chars++;
                break;
            case 's':
                str_arg = va_arg(args, char *);
                if (str_arg == NULL)
                    str_arg = "(null)";
                for (p = str_arg; *p; p++)
                {
                    _putchar(*p);
                    printed_chars++;
                }
                break;
            case 'd':
            case 'i':
                int_arg = va_arg(args, int);
                int_str = inToString(int_arg); 
                for (p = int_str; *p; p++) 
                {
                    _putchar(*p);
                    printed_chars++;
                }
                free(int_str);
                break;
            case '%':
                _putchar('%');
                printed_chars++;
                break;
            default:
                _putchar('%');
                _putchar(*format);
                printed_chars += 2;
                break;
            }
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}


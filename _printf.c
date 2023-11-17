#include "main.h"

/**
 * _printf - Custom printf function to output formatted data
 * @format: Format string containing the directives
 * 
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Move to the next character to check the specifier */
            switch (*format)
            {
                case 'c':
                    count += putchar(va_arg(args, int)); /* Print character */
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char *);
                        if (str)
                        {
                            while (*str)
                            {
                                count += putchar(*str++);
                            }
                        }
                    }
                    break;
                case '%':
                    count += putchar('%'); /* Print percent symbol */
                    break;
                default:
                    count += putchar('%');
                    count += putchar(*format); /* Print as is for unrecognized specifiers */
            }
        }
        else
        {
            count += putchar(*format); /* Print non-format characters as is */
        }
        format++;
    }

    va_end(args);
    return count;
}


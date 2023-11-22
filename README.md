# holbertonschool-printf
# Custom printf Implementation in C

This project is an implementation of the `printf` standard function in C. The `printf` function writes formatted output to the standard output (stdout) and takes a format string and a variable number of arguments. Inside the implementation, the function parses the format string and replaces format specifiers with corresponding values.

## Code Overview

- `main.h`: Header file containing function declarations and necessary includes.

- `_putchar.c`: Contains the custom `_putchar` function that writes a character to the standard output.

- `_printf.c`: Implementation of the custom `_printf` function that mimics the behavior of the standard `printf` function.

## How `_printf` Works

- The `_printf` function takes a format string and a variable number of arguments.

- It uses a `va_list` to handle the variable arguments.

- The function iterates through each character in the format string.

- If the character is not `%`, it is directly written to the standard output using the `_putchar` function, and the `printed_chars` counter is incremented.

- If the character is `%`, the function checks the next character to determine the format specifier.

- It supports format specifiers `%c` (character), `%s` (string), and `%%` (literal percent symbol).

- For `%c`, it retrieves a character argument from the variable arguments and prints it.

- For `%s`, it retrieves a string argument from the variable arguments and prints it. If the string is `NULL`, it prints `"(null)"`.

- For `%%`, it simply prints a percent symbol.

- If the character is not a recognized format specifier, it prints a percent symbol followed by the character.

- The `printed_chars` counter keeps track of the total characters printed.

- Finally, the function returns the total number of characters printed.

## Usage

1. Include the `main.h` header in your C file.

2. Call the `_printf` function with a format string and any additional arguments.

3. The function will print the formatted output to the standard output.

## Supported Specifiers

- `%c`: Print a character.
- `%s`: Print a string.
- `%%`: Print a percent symbol.

##  Contributors
The project contributors are:

Norman Colon Cruz


Flowchart
https://imgur.com/x7idRiC

## Example

```c
#include "main.h"

int main(void)
{
    int len;
    len = _printf("Hello, %s! My favorite number is %d.\n", "world", 42);
    return (0);
}




# holbertonschool-printf
## Custom printf Implementation in C

This project is an implementation of the `printf` standard function in C. The `printf` function writes formatted output to the standard output (stdout) and takes a format string and a variable number of arguments. Our implementation aims to mimic the standard `printf` function's behavior, handling various format specifiers and outputting formatted strings.

### Code Overview

- `main.h`: Header file containing function declarations and necessary includes.
- `_putchar.c`: Contains the custom `_putchar` function for writing a character to the standard output.
- `_printf.c`: The core implementation of the custom `_printf` function, which mimics the standard `printf` function.

### How `_printf` Works

- `_printf` accepts a format string and a variable number of arguments.
- It utilizes a `va_list` to manage the variable arguments.
- The function processes each character in the format string.
- Characters that are not `%` are written to standard output using `_putchar`, incrementing the `printed_chars` counter.
- For `%` characters, the function identifies and processes the following format specifier.
- Supported specifiers include `%c` (character), `%s` (string), and `%%` (percent symbol).
- For `%c`, it prints a character; for `%s`, it prints a string or `"(null)"` if the string is NULL.
- `%%` results in a literal percent symbol.
- Unrecognized specifiers lead to printing the `%` character followed by the unrecognized character.
- The function returns the total count of printed characters.

### Usage

1. Include `main.h` in your C files.
2. Use `_printf` similarly to `printf` with a format string and additional arguments.
3. The function outputs formatted text to standard output.

### Supported Specifiers

- `%c`: Print a character.
- `%s`: Print a string.
- `%%`: Print a percent symbol.

### Contributors

- Norman Colon Cruz


### Example

```c
#include "main.h"

int main(void) {
    int len;
    len = _printf("Hello, %s! My favorite number is %d.\n", "world", 42);
    return 0;
}


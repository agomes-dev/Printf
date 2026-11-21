*This project has been created as part of the 42 curriculum by andrefe2.*

# ft_printf

## Description

**ft_printf** is a project from the 42 Common Core. The goal is to recreate the standard C library function `printf()` by implementing a custom formatted output function.

The project consists of creating a static library (`libftprintf.a`) containing `ft_printf()` and its helper functions.

The function processes a format string containing ordinary characters and conversion specifiers. When a conversion is encountered, it retrieves the corresponding argument using variadic functions and prints it according to its expected type.

The mandatory part supports the following conversions:

| Specifier | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format, preceded by `0x`. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints an integer in decimal format. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned hexadecimal number using lowercase letters. |
| `%X` | Prints an unsigned hexadecimal number using uppercase letters. |
| `%%` | Prints a percent sign. |

The function returns the total number of characters printed, or `-1` if a write operation fails.

The project focuses on variadic functions, recursion, pointers, type conversions, and modular code organization.

## Instructions

### Compilation

From the root of the repository:

```bash
make          # Builds libftprintf.a
make clean    # Removes object files
make fclean   # Removes object files and libftprintf.a
make re       # Rebuilds the library from scratch
```

The Makefile compiles the source files using:

```bash
cc -Wall -Wextra -Werror
```

The resulting static library is named `libftprintf.a`.

### Usage

Include the project header in your C source file:

```c
#include "ft_printf.h"
```

Compile your program by linking it with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf
```

Example:

```c
#include "ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf("Hello, %s! You are %d years old.\n", "World", 42);
	ft_printf("Characters printed: %d\n", count);
	return (0);
}
```

## Technical Choices

### Variadic Functions

The implementation uses the `stdarg.h` library to handle a variable number of arguments.

The following macros are used:

- `va_list`: declares the variable used to access the additional arguments.
- `va_start`: initializes the argument list.
- `va_arg`: retrieves the next argument with the expected type.
- `va_end`: ends the processing of the argument list.

The main function iterates through the format string character by character. When it encounters `%`, it identifies the following conversion specifier and delegates the corresponding operation to a helper function.

### Helper Functions

The implementation is divided into smaller functions, each responsible for a specific output operation:

| Function | Description |
|---|---|
| `ft_putchar` | Prints a single character using `write`. |
| `ft_putstr` | Prints a string, handling `NULL` by displaying `(null)`. |
| `ft_putnbr` | Prints signed decimal integers. |
| `ft_putnbr_un` | Prints unsigned decimal integers. |
| `ft_puthexa` | Prints hexadecimal numbers in lowercase or uppercase. |
| `ft_putpointer` | Prints pointer addresses in hexadecimal format with the `0x` prefix. |
| `ft_percent_type` | Identifies the conversion specifier and calls the appropriate helper function. |

This modular approach keeps the main function focused on processing the format string and makes each conversion easier to understand, test, and maintain.

### Algorithm and Number Conversion

The project uses recursion to print decimal and hexadecimal numbers in the correct order.

For decimal numbers, the algorithm repeatedly divides the number by 10 until it reaches the most significant digit. The recursive calls then return, printing each digit from left to right.

For hexadecimal numbers, the same principle is applied using division and remainder by 16. A lookup string containing the hexadecimal digits (`0123456789abcdef` or `0123456789ABCDEF`) is used to convert each remainder into its corresponding character.

Signed integers are handled using a `long` variable internally. This allows the function to safely process the minimum value of an `int` (`-2147483648`), whose positive counterpart cannot be represented by an `int`.

Pointer addresses are converted to an unsigned integer type before being printed in hexadecimal format.

### Error Handling

Each helper function checks the return value of `write` through `ft_putchar`.

If a write operation fails, the error is propagated through the helper functions, and `ft_printf` returns `-1`.

The number of successfully printed characters is accumulated and returned when the operation completes successfully.

## Resources

### References

- [42 School](https://42.fr/) — Project subject and curriculum.
- [cppreference – Variadic functions](https://en.cppreference.com/w/c/variadic) — Documentation about `va_list`, `va_start`, `va_arg`, and `va_end`.
- [Linux man-pages – write(2)](https://man7.org/linux/man-pages/man2/write.2.html) — Documentation about the `write` system call and its return value.
- [GNU C Library – Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html) — Reference for the behaviour of standard formatted output functions.
- [cppreference – C](https://en.cppreference.com/w/c) — General C language documentation.
- The 42 Norm (Norminette).

### Use of AI

AI (ChatGPT) was used as a tutor and code reviewer throughout the project, rather than as a tool to generate the complete implementation.

It was used for:

- Explaining C concepts related to variadic functions, pointers, recursion, integer types, and hexadecimal conversion.
- Understanding how `printf` processes format strings and retrieves arguments of different types.
- Reviewing the implementation of helper functions and identifying logical errors, incorrect types, and potential improvements.
- Discussing the organization of the main `ft_printf` function and how to connect the different helper functions.
- Understanding error handling, return values, and character counting.

The implementation was developed step by step. The code was written and reviewed by me, using AI explanations and feedback to understand the reasoning behind each function and make corrections independently.

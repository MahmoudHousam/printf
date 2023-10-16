# Printf

```c
int printf ( const char * format, ... );
```

Simulating the way how the **[printf (3)](http://man7.org/linux/man-pages/man3/printf.3.html)** function of the programming language C works. **\_printf**

This function is a part of the C standard library **<stdio.h>** and to use it we must specify the header file **<stdio.h>**.

**\_printf** takes a string pointed to by format and print it typically in console. It can take also other arguments as format specifiers using the placeholder **%** and handle them according to their data type _(int, float, double float, char, etc)_

### Parameters

> **format** -> C string that contains the text to be written to stdout.

Followed by the passed arguements, if existed, and translate these parameters according to their respective placeholder _%+character_. Check the following table:
Specifier | Output | Example
------------ | ------------- |-----------
% | A % followed by another % character will write a single % to the stream| %
c | Character | A
s | String of characters | Holberton
i or d | Signed decimal integer | 98
b | Unsigned binary | 101010
u | Unsigned decimal integer | 98
o | Unsigned octal | 5523
x | Unsigned hexadecimal integer (lowercase) | 36264eb
X | Unsigned hexadecimal integer (uppercase) | 36264EB
r | Reversed string | gnirts |
R | Rot13 string | cevags

##### Return Value.

Upon **success**, the **total number** of characters written is returned.
In case of errors, the error indicator **ferror** is set and a negative number is returned.

## The tasks.

-[x] **I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life.**
Write a function that produces output according to a format.

- Prototype:`int _printf(const char *format, ...);`
- Returns: the number of characters printed (excluding the null byte used to end output to strings)
- write output to stdout, the standard output stream
- format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
  -- `c`
  -- `s`
  -- `%`

  -[x] **Education is when you read the fine print. Experience is what you get if you don't**
  Handle the following conversion specifiers:
  -- `d`
  --`i`

## Functions to use:

```c
int _putchar(char c); /*writes the character c to stdout */
int _printf(const char *format, ...);/* function that produces output according to a format.*/
int print_char(va_list c);/*writes the character c to stdout */
int print_string(va_list s);/*writes the character c to stdout */
int print_int(va_list i);/*function that prints an integer */
int print_dec(va_list d);/* function that prints an decimal*/
```

## How to use.

### Complilation

All of the `.c` files along with a main.c file are to be compiled with `gcc 4.8.4` on Ubuntu 14.04 LTS with the flags `-Wall Werror` `-Westra` and `-pedantic.`

The files will be compiled this way:

- `gcc -Wall -Werror -Wextra -pedantic *.c`

#### Use.

In the `main.c` file, use the `_printf` function like so:

```c
#include "main.h"
/**
 * main - main function of program
 * Return: always 0
 */
int main(void)
{
	int num;
	char *string;

	num = 98;
	string = "Hello, Holberon!";
	_printf("%s is %i.\n", string, num);
	return (0);
}
```

```{bash}
linux>$  gcc -Wall -Werror -Wextra -pedantic *.c -o printf_program
linux>$  ./printf_program
Hello, Holberton is 98.
linux>$
```

## Contributors

- [Mahmoud Housam](https://github.com/MahmoudHousam)
- [Ali Khaled](https://github.com/alikhaled17)

#include "main.h"

/**
 * print_character - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculate active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Number of chars printed
 */
int print_character(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_character(c, buffer, flags, width, precision, size));
}

/**
 * print_percentage - Prints a percent sign
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculate active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Number of chars printed
 */
int print_percentage(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	NOTUSED(types);
	NOTUSED(buffer);
	NOTUSED(width);
	NOTUSED(flags);
	NOTUSED(size);
	NOTUSED(precision);
	return (write(1, "%%", 1));
}

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculate active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	NOTUSED(flags);
	NOTUSED(buffer);
	NOTUSED(precision);
	NOTUSED(width);
	NOTUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & FO_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_binary - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculate active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	NOTUSED(flags);
	NOTUSED(buffer);
	NOTUSED(width);
	NOTUSED(size);
	NOTUSED(precision);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * print_integer - Print int
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculate active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Number of chars printed
 */
int print_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_num(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

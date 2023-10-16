#include "main.h"

/**
 * print_non_printable - Prints ascii codes in hexacode of non printable chars
 * @types: Arguments list 
 * @buffer: Buffer array handle print
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Number chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_ptr(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += adding_hex_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_ptr - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array handle print
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Number chars printed.
 */
int print_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFFER_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	NOTUSED(width);
	NOTUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';
	NOTUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & FO_ZERO) && !(flags & FO_MINUS))
		padd = '0';
	if (flags & FO_PLUS)
		extra_c = '+', length++;
	else if (flags & FO_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFFER_SIZE - i - 1));*/
	return (write_ptr(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_rot13_string - Print a string in rot13.
 * @types: Arguments list 
 * @buffer: Buffer array handle print
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Numbers of chars printed
 */
int print_rot13_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

/**
 * print_reverse - Prints reverse string.
 * @types: Arguments list 
 * @buffer: Buffer array handle print
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		NOTUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

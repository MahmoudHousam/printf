#include "main.h"

/**
 * print_oct - Print an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array handle print
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Number of chars printed
 */
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	NOTUSED(width);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & FO_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_unsigned - Print an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array handle print
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadec - Print an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array handle print
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Number of chars printed
 */
int print_hexadec(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa - Print a hexadec number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array handle print
 * @flags:  Calculate active flags
 * @flag_ch: Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifer
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	NOTUSED(width);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & FO_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadec_upper - Print an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array handle print
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifer
 * Return: Number of chars printed
 */
int print_hexadec_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @format: Formattd string in which print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculate active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifer
 * Return: 1 or 2;
 */
int handle_print(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	format_t format_types[] = {
		{'i', print_integer}, {'d', print_integer}, {'b', print_binary},
		{'c', print_character}, {'s', print_string}, {'%', print_percentage},
		{'X', print_hexadec_upper}, {'p', print_ptr}, {'S', print_non_printable},
		{'u', print_unsigned}, {'o', print_oct}, {'x', print_hexadec},
		{'r', print_reverse}, {'R', print_rot13_string}, {'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*ind] == format_types[i].format)
			return (format_types[i].fn(list, buffer, flags, width, precision, size));

	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &format[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}

#include "main.h"

void get_buffer(char buffer[], int *buffer_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int flags, width, precision, size, buffer_ind = 0;
	int i, printed = 0, printed_chars = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_ind++] = format[i];
			if (buffer_ind == BUFFER_SIZE)
				get_buffer(buffer, &buffer_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			flags = print_flags(format, &i);
			get_buffer(buffer, &buffer_ind);
			precision = print_precision(format, &i, list);
			size = print_size(format, &i);
			width = print_width(format, &i, list);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	get_buffer(buffer, &buffer_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * get_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffer_ind: Index at which to add next char, represents the length.
 */
void get_buffer(char buffer[], int *buffer_ind)
{
	if (*buffer_ind > 0)
		write(1, &buffer[0], *buffer_ind);

	*buffer_ind = 0;
}

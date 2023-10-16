#include "main.h"

/**
 * print_size - Calculate size to cast the argument
 * @format: Formatted string which print the arguments
 * @i: Arguments list be printed.
 *
 * Return: Precision
 */
int print_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = LONG_STRING;
	else if (format[curr_i] == 'h')
		size = SHORT_STRING;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

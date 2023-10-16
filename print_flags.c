#include "main.h"

/**
 * print_flags - Calculate active flags
 * @format: Formattd string in which print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int print_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGSS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGSS_ARR[] = {FO_MINUS, FO_PLUS, FO_ZERO, FO_HASH, FO_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGSS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGSS_CH[j])
			{
				flags |= FLAGSS_ARR[j];
				break;
			}

		if (FLAGSS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}

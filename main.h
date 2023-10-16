#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define NOTUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FO_MINUS 1
#define FO_PLUS 2
#define FO_ZERO 4
#define FO_HASH 8
#define FO_SPACE 16

/* SIZES */
#define LONG_STRING 2
#define SHORT_STRING 1

/**
 * struct format - Struct op
 *
 * @format: The format.
 * @fn: The function associated.
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format format_t - Struct op
 *
 * @format: The format.
 * @fm_t: The function associated.
 */
typedef struct format format_t;

int _printf(const char *format, ...);
int handle_print(const char *format, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_character(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percentage(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadec(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadec_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifers */
int print_flags(const char *format, int *i);
int print_width(const char *format, int *i, va_list list);
int print_precision(const char *format, int *i, va_list list);
int print_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_character(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_ptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_ptr(char);
int adding_hex_code(char, char[], int);
int is_dgt(char);

long int convert_size_num(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif /* MAIN_H */

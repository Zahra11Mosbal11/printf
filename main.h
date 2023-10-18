#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
* struct format - struct token
* @id: format token
* @f: The function associated
*/
typedef struct format
{
	char *id;
	int (*f)();
} match;

void flush_buffer(char *buffer, int *length);
void print_ather(char str);
int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list val);
int printf_string(va_list val);
int _strlen(char *str);
int _strlenc(const char *str);
int print_37(void);
int print_int(va_list args);
int put_d(va_list args);
#endif

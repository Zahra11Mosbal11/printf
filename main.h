#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

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
int print_ather(int cont, char str);
int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list val);
int printf_string(va_list val);
int _strlen(char *str);
int _strlenc(const char *str);
int print_37(void);
#endif

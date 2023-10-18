#include "main.h"
/**
 * print_char - start
 * @val: argument
 * Return: 1
 */
int print_char(va_list val)
{
	char str;

	str = va_arg(val, int);
	_putchar(str);
	return (1);

}
/**
 * print_ather - start
 *
 * @str: the format str
 * Return: intger
 */
void print_ather(char str)
{

	_putchar('%');
	_putchar(str);
}

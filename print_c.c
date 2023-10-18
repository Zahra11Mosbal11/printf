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
 * @cont: the cont
 * @str: the format str
 * Return: intger
 */
int print_ather(int cont, char str)
{
	int i = cont;

	_putchar('%');
	i++;
	_putchar(str);
	i++;
	return (i);
}

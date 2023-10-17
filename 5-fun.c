#include "main.h"
<<<<<<< HEAD
=======

>>>>>>> 344e2960bf24082b24973de8cd4a38ea1ef6c328
/**
 * p_n_l_sh - Print with options
 * @str: The base
 * @params: Struct of params
 * Return: Chars printed
 */

int p_n_l_sh(char *str, par_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_f && !params->minus_f)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_f)
		str++;
	else
		neg = 0;
	if (params->plus_f && !neg2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_f && !neg2 && !params->unsign)
		n += _putchar(' '), i++;
	n += puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}

/**
 * put_b - print binary
 * @ap: list
 * @params: struct
 * Return: bytes printed
 */

int put_b(va_list ap, par_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_f && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * put_X - print octal
 * @ap: list
 * @params: par
 * Return: some
 */

int put_X(va_list ap, par_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_mod)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_f && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * put_x - print octal
 * @ap: list
 * @params: par
 * Return: some
 */

int put_x(va_list ap, par_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_mod)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
	l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_f && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * put_o - print octal
 * @ap: list
 * @params: par
 * Return: some
 */

int put_o(va_list ap, par_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_mod)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 8, CONVERT_UNSIGNED, params);
	if (params->hashtag_f && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

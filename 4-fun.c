#include "main.h"
/**
 * put_p - Prints address
 * @ap: Argument
 * @params: struct of parameters
 *
 * Return: printed bytes
 */

int put_p(va_list ap, par_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	else
	{
		str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
		*--str = 'x';
		*--str = '0';
	}
	return (print_number(str, params));
}

/**
 * isdigit - Checks if its a digit
 * @c: The int to be checked
 * Return: 0 when false, 1 when true
 */

int is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * _strlen - Calculates length of a string
 * @s: The string
 * Return: The length
 */

int _strlen(char *s)
{
	int i = 0;

	do {
		i++;
		s++;
	} while (*s != '\0');

	return (i);
}

/**
 * print_number - Prints numbers with options
 * @str: The number string
 * @params: Struct of parameters
 * Return: Chars printed
 */

int print_number(char *str, par_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->prec && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->prec != UINT_MAX)
	{
		while (i++ < params->prec)
			*--str = '0';
	}
	if (neg)
		*--str = '-';
	if (!params->minus_f)
		return (p_n_r_sh(str, params));
	else
		return (p_n_l_sh(str, params));
}

/**
 * p_n_r_sh - Print number right shift
 * @str: String
 * @params: Struct params
 * Return: int
 */

int p_n_r_sh(char *str, par_t *params)
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
	if ((params->plus_f && !neg2) ||
		(!params->plus_f && params->space_f && !neg2))
		i++;

	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_f && !neg2 && pad_char == '0' &&
		!params->unsign)
		n += _putchar('+');
	else if (!params->plus_f && !neg2 && params->space_f &&
		!params->unsing && params->zero_f)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_f && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_f && params->space_f && !neg2 &&
		!params->unsign && !params->zero_f)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

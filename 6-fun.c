#include "main.h"

/**
 * put_percent - print percent
 * @ap: list
 * @params: pare
 * Return: sum
 */

int put_percent(va_list ap, par_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * put_int - put int
 * @ap: list
 * @params: par
 * Return: sum
 */

int put_i(va_list ap, par_t *params)
{
	long l;

	if (params->l_mod)
		l = va_arg(ap, long);
	else if (params->h_mod)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * put_c - pala
 * @ap: list
 * @params: pare
 * Return: sum
 */

int put_c(va_list ap, par_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->minus_f)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_f)
		sum += _putchar(ch);
	return (sum);
}

/**
 * put_s - put string
 * @ap: list
 * @params: pala
 * Return: something
 */

int put_s(va_list ap, par_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STR;

	j = pad = _strlen(str);
	if (params->prec < pad)
		j = pad = params->prec;

	if (params->minus_f)
	{
		if (params->prec != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ > params->width)
		sum += _putchar(pad_char);
	if (!params->minus_f)
	{
		if (params->prec != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * put_S - puts string in a way
 * @ap: list
 * @params: parametrs
 * Return: sum
 */

int put_S(va_list ap, par_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STR));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}

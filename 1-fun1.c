#include "main.h"
/**
* init_params - clears struct fields and reset buf
* @params: the parameters struct
* @ap: the argument pointer
*
* Return: void
*/
void init_params(par_t *params, va_list ap)
{
	params->unsign = 0;
	params->plus_f = 0;
	params->space_f = 0;
	params->hashtag_f = 0;
	params->zero_f = 0;
	params->minus_f = 0;
	params->width = 0;
	params->prec = UINT_MAX;
	params->h_mod = 0;
	params->l_mod = 0;
	(void) ap;
}

/**
 * _puts - start
 *
 * @str: string
 * Return: integer
 */
int _puts(char *str)
{
	char *a = str;

	while (str)
		_putchar(*str++);
	return (str - a);
}

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(int c)
{
	static int i;
	static char buf[OUT_BUF];

	if (c == BUF_FLUSH || i >= OUT_BUF)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
* g_specifier - finds the format func
* @s: the format strings
*
* Return: the number of bytes printed
*/
int (*g_specifier(char *s))(va_list ap, par_t *params)
{
	specifier_t specifiers[] = {
		{"c", put_c},
		{"d", put_i},
		{"i", put_i},
		{"s", put_s},
		{"%", put_percent},
		{"b", put_b},
		{"o", put_o},
		{"u", put_u},
		{"x", put_x},
		{"X", put_X},
		{"p", put_p},
		{"S", put_S},
		{"r", put_r},
		{"R", put_R},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
* g_print_func - finds the format func
* @s: the format string
* @ap: argument pointer
* @params: the parameters struct
*
* Return: the number of bytes printed
*/
int g_print_func(char *s, va_list ap, par_t *params)
{
	int (*f)(va_list, par_t *) = g_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

#include "main.h"
#include <stdio.h>

/**
* g_mod - finds the modifier func
* @s: the format string
* @params: the parameters struct
*
* Return: if modifier was valid
*/
int g_mod(char *s, par_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_mod = 1;
			break;
		case 'l':
			i = params->l_mod = 1;
			break;
	}
	return (i);
}

/**
* g_width - gets the width from the format string
* @s: the format string
* @params: the parameters struct
* @ap: the argument pointer
*
* Return: new pointer
*/
char *g_width(char *s, par_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))

			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}

/**
* g_prec - get the precision from the format string
* @p: the format string
* @params: the parameters struct
* @ap: the argument pointer
*
* Return: new pointer
*/
char *g_prec(char *p, par_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;

	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))

			d = d * 10 + (*p++ - '0');
	}
	params->prec = d;
	return (p);
}

/**
* print_from_to - prints a range of char addresses
* @start: starting address
* @stop: stopping address
* @except: except address
*
* Return: number bytes printed
*/
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

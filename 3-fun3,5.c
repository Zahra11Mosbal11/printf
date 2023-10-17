#include "main.h"
#include <stdlib.h>
/**
* convert - converter function, a clone of itoa
* @num: number
* @base: base
* @flags: argument flags
*
* Return: string
*/
char *convert(long int num, int base, int flags)
{
	char *array;
	char *result = NULL;
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	int numDigits = 0;
	unsigned long temp = n;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	do {
		numDigits++;
		temp /= base;
	} while (temp > 0);
	result = (char *)malloc(numDigits + 2);
	if (result == NULL)
	{
		return (NULL);
	}
	ptr = result + numDigits + 1;
	*ptr = '\0';
	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (result);
}
/**
* put_u - prints unsigned integer numbers
* @ap: argument pointer
* @params: the parameters struct
* Return: bytes printed
*/
int put_u(va_list ap, par_t *params)
{
	unsigned long l;

	if (params->l_mod)
		l = (unsigned long) va_arg(ap, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED), params));
}

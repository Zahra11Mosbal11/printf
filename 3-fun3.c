#include "main.h"
/**
* g_flag - finds the flag func
* @s: the format string
* @params: the parameters struct
*
* Return: if flag was valid
*/
int g_flag(char *s, par_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_f = 1;
			break;
		case ' ':
			i = params->space_f = 1;
			break;
		case '#':
			params->hashtag_f = 1;
			break;
		case '-':
			i = params->minus_f = 1;
			break;
		case '0':
			i = params->zero_f = 1;
			break;
	}
	return (i);
}
/**
* put_r - prints string in reverse
* @ap: string
* @params: the parameters struct
* Return: number bytes printed
*/
int put_r(va_list ap, par_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar (*str);
	}
	return (sum);
}
/**
* put_R - prints string in rot13
* @ap: string
* @params: the parameters struct
*
* Return: number bytes printed
*/
int put_R(va_list ap, par_t *params)
{
	int i, index;
	int count = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);

	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar (arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}

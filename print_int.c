#include "main.h"

/**
 * print_int - integers
 * @args: args
 * Return: num of printed char
 */

int print_int(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, dig, ex = 1;
	int i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			ex = ex * 10;
			num = num / 10;
		}
		num = n;
		while (ex > 0)
		{
			dig = num / ex;
			_putchar(dig + '0');
			num = num - (dig * ex);
			ex = ex / 10;
			i++;
		}
	}
	_putchar(last + '0');
	return (i);
}

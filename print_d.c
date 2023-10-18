#include "main.h"

/**
 * put_d - dec
 * @args: la
 * Return: man
 */

int put_d(va_list args)
{
	char array[12];
	int m = 0;
	int neg = 0;
	int dec = va_arg(args, int);
	int c = 0;
	int i;

	if (dec < 0)
	{
		neg = 1;
		dec = -dec;
	}
	while (dec > 0)
	{
		array[m++] = (dec % 10) + '0';
		dec /= 10;
	}
	if (neg == 1)
		array[m++] = '-';

	i = m - 1;
	while (i >= 0)
	{
		_putchar(array[i]);
		c++;
		i--;
	}
	return (c);
}

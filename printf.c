#include "main.h"
/**
 * _printf - Entry point
 * @format: the arguments
 *Return: intiger
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int cont = 0;

	va_start(args, format);

		while (format && format[i])
		{
			if (format[i] == '%')
			{
				i++;
				switch (format[i])
				{
					case 'c':
						print_char(args);
						cont++;
						break;
					case 's':
						cont += printf_string(args);
						break;
					case '%':
						print_37();
						cont++;
						break;
					case 'i':
						cont += print_int(args);
						break;
					case 'd':
						cont += put_d(args);
						break;
					default:
						print_ather(format[i]);
						cont += 2;
						break;
				}
			}
			else
			{
				_putchar(format[i]);
				cont++;
			}
			i++;
		}
	va_end(args);
	return (cont);
}

#include "main.h"
/**
 * _printf - Entry point
 * @format: the arguments
 *Return: intiger
*/
int _printf(const char *format, ...)
{
	va_list args;
	int cont = 0,i = 0;

	va_start(args, format);
		while (format && format[i])
		{
			if (format[i] == '%')
			{
				i++;
				switch (format[i])
				{
					case 'c':
						cont += print_char(args);
						break;
					case 's':
						cont += printf_string(args);
						break;
					case '%':
						cont += print_37();
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
				cont += _putchar(format[i]);
			}
			i++;
		}
	va_end(args);
	return (cont);
}

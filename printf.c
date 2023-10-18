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
	int cont;

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
						printf_string(args);
						cont++;
						break;
					case '%':
						print_37();
						cont++;
						break;
					default:
						cont += print_ather(cont, format[i]);
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

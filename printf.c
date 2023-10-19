#include "main.h"
/**
 * _printf - Entry point
 * @format: the arguments
 *Return: intiger
*/
int _printf(const char *format, ...)
{
	va_list args;
	int cont = 0, i = 0;
	char buffer[BUFFER_SIZE];

	va_start(args, format);
		while (format && format[i])
		{
			if (cont >= BUFFER_SIZE)
				flush_buffer(buffer, &cont);
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
					default:
						print_ather(format[i]);
						cont += 2;
						break;
				}
			}
			else
			{
				buffer[cont++] = format[i];
			}
			i++;
		}
	flush_buffer(buffer, &cont);
	va_end(args);
	return (cont);
}

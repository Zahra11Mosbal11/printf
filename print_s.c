#include "main.h"
/**
 * printf_string  - Entry point
 *@val: argument
 *Return: length
*/
int printf_string(va_list val)
{
	char *str;
	int i;
	int length;
	int j = 0;
	char buffer[BUFFER_SIZE];

	str = va_arg(val, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	length = _strlen(str);
	for (i = 0; i < length; i++)
	{
		if (j >= BUFFER_SIZE)
			flush_buffer(buffer, &j);
		buffer[j++] = str[i];
	}
	flush_buffer(buffer, &j);
	return (length);
}
/**
 * _strlen - Entry point
 * @str: the string
 * Return: i
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
/**
 * _strlenc - Entry point
 * @str: the string
 * Return: i
 */
int _strlenc(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
/**
 * flush_buffer - start
 * @buffer: the string
 * @length: the length of string
 *
 * Return: void
 */
void flush_buffer(char *buffer, int *length)
{
	int i;

	for (i = 0; i < *length; i++)
	{
		_putchar(buffer[i]);
	}
}

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

	str = va_arg(val, char *);
	if (str == NULL)
	{
		str = "(null)";
		length = _strlen(str);
		for (i = 0; i < length; i++)
			_putchar(str[i]);
		return (length);
	}
	else
	{
		length = _strlen(str);
		for (i = 0; i < length; i++)
			_putchar(str[i]);
		return (length);
	}

}
/**
 * _strlen - Entry point
 * @str: the string
 * Return: i
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
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

	for (i = 0; str[i] != 0; i++)
		;
	return (i);
}











#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
int len, len2;
char *str = "When you invoke GCC , it normally does preprocessing, compilation, assembls not the default.\n";

	len = _printf("man gcc:\n%s", str);
	len2 = printf("man gcc:\n%s", str);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	_printf("%d, l, %i,\n", -762534, len);
	return (0); 
}

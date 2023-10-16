#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.I>

#define OUT_BUF 1024
#define BUF_FLUSH  -1

#define NULL _STR " (null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
/**
* struct parameters - parameters struct
* @unsign: flag if unsigned value
*
* @plus_f: on if plus flag specified
* @space_f: on if hashtag_flag specified
* @hashtag_f: on if flag specified
* @zero_f: on if _flag specified
* @minus_f: on if flag specified
* @width: field width specified
* @prec: field precision specified
* @h_mod: on if h modifier is specified
* @l_mod: on if1 modifier is specified
*/
typedef struct parameters
{
	unsigned int unsign	:1;

	unsigned int plus_f	:1;
	unsigned int space_f	:1;
	unsigned int hashtag_f	:1;
	unsigned int zero_f	:1;
	unsigned int minus_f	:1;

	unsigned int width;
	unsigned int prec;

	unsigned int h_mod	:1;
	unsigned int l_mod	:1;

} par_t;


/**
* struct specifier - struct token
* @specifier: format token
* @f: The function associated
*/
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, par_t *);
} specifier_t;

/*put.c module */
int _puts(char *str);
int _putchar(int c);

/* print functions.c module */
int put_c(va_list ap, par_t *params);
int put_i(va_list ap, par_t *params);
int put_s(va_list ap, par_t *params);
int put_percent(va_list ap, par_t *params);
int put_S(va_list ap, par_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, par_t *params);
int put_u(va_list ap, par_t *params);
int put_p(va_list ap, par_t *params);

/* specifier.c module* */
int (*g_specifier(char *s))(va_list ap, par_t *params);
int g_print_func(char *s, va_list ap, par_t *params);
int g_flag(char *s, par_t *params);
int g_mod(char *s, par_t *params);
char *g_width(char *s, par_t *params, va_list ap);

/* convert number.c module */
int put_x(va_list ap, par_t *params);
int put_X(va_list ap, par_t *params);
int put_b(va_list ap, par_t *params);
int put_o(va_list ap, par_t *params);

/* simple printers.c module */
int print_from to(char *start, char *stop, char *except);
int put_r(va_list ap, par_t *params);
int put_R(va_list ap, par_t *params);

/* print number.c module */
int isdigit(int c);
int strlen(char *s);
int print_number(char *str, par_t *params);
int p_n_r_sh(char *str, par_t *params);
int p_n_l_sh(char *str, par_t *params);

/* params.c module */
void init_params(par_t *params, va_list ap);

/* string fields.c module */
char *g_prec(char *p, par_t *params, va_list ap);

/*_prinf.d module */
int _printf(const char *format, ...);

#endif

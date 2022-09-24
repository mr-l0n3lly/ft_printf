#ifndef FT_PRINTF_H
#define FT_PRINTF_H

/*
 * System header files needed
 */
#include <stdarg.h>
#include <stdio.h>

/*
 * User defined include files
 */
#include "libft.h"

/*
 * Defined structures
 */
typedef struct  s_flag
{
    int         sign;
    int         zero;
    int         space;
    int         zero_padding;
    int         point;
    int         dash;
    int         h;
    int         l;
    int         j;
    int         z;
}               t_flag;

typedef struct  s_arg
{
    va_list     current;
    int         width;
    int         max_width;
    int         print_length;
    int         n_bytes;
    t_flag      *flags;
}               t_arg;

/*
 * Defined functions
 */
int     ft_printf(char  *format, ...);
t_arg   *ft_initiate(t_arg *);
void    ft_print_char(t_arg*);
void    ft_print_str(t_arg*, char*);
void    ft_print_s(t_arg*);
void    ft_print_number(t_arg*);
void    ft_print_unsigned_number(t_arg *arg);
int     ft_get_conversion(t_arg*, const char*, int);
int     ft_parse(t_arg *, const char *, int);
void    ft_put_char(t_arg*, char);
void    ft_get_modifiers(t_arg*, const char *, int);
void    ft_get_width(t_arg*, const char *, int);
void    ft_get_flags(t_arg*, const char *, int);
void    ft_put_str(t_arg *arg, char *str);
void    ft_print_right_width(t_arg *arg, void (*)(t_arg*, char *), char *);
void    ft_print_left_width(t_arg *arg, void (*)(t_arg*, char *), char *);

#endif

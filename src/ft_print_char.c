//
// Created by Andrei Pavalachi on 15.09.2022.
//
#include "ft_printf.h"

void    ft_print_char(t_arg *arg)
{
    char c = (char)va_arg(arg->current, int);
    ft_put_char(arg, c);
}
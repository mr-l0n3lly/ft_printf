//
// Created by Andrei Pavalachi on 15.09.2022.
//
#include "ft_printf.h"

void    ft_print_number(t_arg *arg)
{
    int num;

    num = va_arg(arg->current, int);
    ft_putnbr(num);
    arg->n_bytes += (int)ft_strlen(ft_itoa(num));
}
//
// Created by Andrei Pavalachi on 15.09.2022.
//
#include "ft_printf.h"

void    ft_print_number(t_arg *arg)
{
    long long num;

    if (arg->flags->l == 1)
    {
        num = va_arg(arg->current, long int);
    }

    if (arg->flags->l == 2)
    {
        num = va_arg(arg->current, long long int);
    }

    if (arg->flags->l == 0)
    {
        num = va_arg(arg->current, int);
    }

    ft_print_str(arg, ft_itoa((int)num));
}

void    ft_print_unsigned_number(t_arg *arg)
{
    unsigned long long num;

    if (arg->flags->l == 1)
    {
        num = va_arg(arg->current, unsigned long int);
    }

    if (arg->flags->l == 2)
    {
        num = va_arg(arg->current, unsigned long long int);
    }

    if (arg->flags->l == 0)
    {
        num = va_arg(arg->current, unsigned int);
    }

    ft_print_str(arg, ft_itoa((int)num));
}
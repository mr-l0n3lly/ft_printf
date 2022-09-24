//
// Created by Andrei Pavalachi on 15.09.2022.
//
#include "ft_printf.h"


void    ft_print_left_width(t_arg *arg, void (*print_func)(t_arg*, char*), char *c)
{
    int i = 0;
    char space_char = ' ';

    if (arg->flags->zero)
    {
        space_char = '0';
    }

    while (i < arg->width - 1)
    {
        ft_put_char(arg, space_char);
        i++;
    }

    print_func(arg, c);
}

void    ft_print_right_width(t_arg *arg, void (*print_func)(t_arg*, char*), char *c)
{
    int i = 0;
    char space_char = ' ';

    if (arg->flags->zero)
    {
        space_char = '0';
    }

    print_func(arg, c);

    while(i < arg->width - 1)
    {
        ft_put_char(arg, space_char);
        i++;
    }
}

void    ft_print_char(t_arg *arg)
{
    char c = (char)va_arg(arg->current, int);
    char str[2] = {c, '\0'};

    if (arg->width)
    {
        if (arg->flags->dash)
        {
            return ft_print_right_width(arg, ft_put_str, str);
        }
        else
        {
            return ft_print_left_width(arg, ft_put_str,str);
        }
    }

    ft_put_str(arg, str);
}

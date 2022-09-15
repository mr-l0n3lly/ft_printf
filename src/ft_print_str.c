//
// Created by Andrei Pavalachi on 15.09.2022.
//
#include "ft_printf.h"

void    ft_print_str(t_arg *arg)
{
    wchar_t *str;

    if (arg->flags->l == 1)
    {
        str = va_arg(arg->current, wchar_t*);
    }
    else
    {
        str = (wchar_t*)va_arg(arg->current, char*);
    }

    ft_putstr((char*)str);
    arg->n_bytes += (int)ft_strlen((char*)str);
}

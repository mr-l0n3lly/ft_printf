//
// Created by Andrei Pavalachi on 15.09.2022.
//
#include "ft_printf.h"

void    ft_print_s(t_arg *arg)
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

    ft_print_str(arg, (char*)str);
}

void    ft_print_str(t_arg *arg, char* str)
{
    if (arg->max_width != 0)
    {
        arg->width = arg->width - arg->max_width + 1;

        if (arg->width < 0)
        {
            arg->width = 0;
        }

        str = ft_strsub((char*)str, 0, arg->max_width);
    }

    if (arg->flags->dash)
    {
        return ft_print_right_width(arg, ft_put_str, (char*)str);
    }

    ft_print_left_width(arg, ft_put_str, (char*)str);

}

void ft_put_str(t_arg *arg, char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        ft_put_char(arg, str[i]);
        i++;
    }
}

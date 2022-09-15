#include "ft_printf.h"

int     ft_get_conversion(t_arg *arg, const char *format, int index)
{
    switch (format[index])
    {
        case 'c':
            ft_print_char(arg);
            break;
        case 's':
            ft_print_str(arg);
            break;
        case 'd':
            ft_print_number(arg);
            break;
        case '%':
            ft_put_char(arg, '%');
        case 'i':
            ft_print_number(arg);
            break;
    }

    return (++index);
}

void    ft_get_modifiers(t_arg* arg, const char *format, int index)
{
    if (format[index] == '-')
    {
        arg->flags->dash = 1;
    }

    if (format[index] == '.')
    {
        arg->flags->point = 1;
    }

    if (format[index] == '+')
    {
        arg->flags->sign = 1;
    }

    if (format[index] == ' ')
    {
        arg->flags->space = 1;
    }

    if (format[index] == '0')
    {
        if (arg->width != 0)
        {
            arg->width *= 10 + 0;
        }
        else
        {
            arg->flags->zero = 1;
        }
    }
}

void    ft_get_width(t_arg *arg, const char *format, int index)
{
    if (ft_isdigit(format[index]) == 1 && format[index] != '0')
    {
        if (arg->flags->point)
        {
            arg->max_width = arg->max_width * 10 + ft_atoi(ft_strsub(format, index, 1));
        }
        else
        {
            arg->width = arg->width * 10 + ft_atoi(ft_strsub(format, index, 1));
        }
    }
}

void    ft_get_flags(t_arg *arg, const char *format, int index)
{
    if (format[index] == 'h')
    {
        arg->flags->h++;
    }

    if (format[index] == 'l')
    {
        arg->flags->l++;
    }

    if (format[index] == 'j')
    {
        arg->flags->j++;
    }

    if (format[index] == 'z')
    {
        arg->flags->z++;
    }
}

void    ft_put_char(t_arg* arg, char c)
{
    ft_putchar(c);
    arg->n_bytes++;
}

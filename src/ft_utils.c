#include "ft_printf.h"

int     ft_get_conversion(t_arg *arg, const char *format, int index)
{
    switch (format[index])
    {
        case 'c':
            ft_print_char(arg);
            break;
        case 'C':
            ft_print_char(arg);
        case 's':
            ft_print_s(arg);
            break;
        case 'S':
            arg->flags->l = 1;
            ft_print_s(arg);
        case 'd':
            ft_print_number(arg);
            break;
        case 'D':
            arg->flags->l = 1;
            ft_print_number(arg);
        case 'i':
            ft_print_number(arg);
            break;
        case 'u':
            ft_print_unsigned_number(arg);
            break;
        case 'U':
            arg->flags->l = 1;
            ft_print_unsigned_number(arg);
        case '%':
            ft_put_char(arg, '%');
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
        else if (arg->max_width != 0)
        {
            arg->max_width *= 10 + 0;
        }
        else
        {
            arg->flags->zero = 1;
        }
    }
}

void    ft_get_width(t_arg *arg, const char *format, int index)
{
    if (ft_isdigit(format[index]) != 0 && format[index] != '0')
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

#include "ft_printf.h"


typedef struct  s_flag
{
    int         sign;
    int         zero;
    int         percent;
    int         space;
    int         zero_padding;
    int         point;
    int         dash;
}               t_flag;

typedef struct  s_arg
{
    va_list     current;
    int         width;
    int         precision;
    int         print_length;
    int         n_bytes;
    t_flag      *flags;
}               t_arg;

t_arg   *ft_initiate(t_arg *tmp)
{
    tmp->width = 0;
    tmp->precision = 0;
    tmp->n_bytes = 0;
    tmp->flags->dash = 0;
    tmp->flags->percent = 0;
    tmp->flags->point = 0;
    tmp->flags->sign = 0;
    tmp->flags->space = 0;
    tmp->flags->zero = 0;
    tmp->flags->zero_padding = 0;

    return (tmp);
}

void    ft_print_char(t_arg *arg)
{
    char c = (char)va_arg(arg->current, int);
    arg->n_bytes++;

    ft_putchar(c);
}

void    ft_print_str(t_arg *arg)
{
    char *str;

    str = va_arg(arg->current, char*);
    arg->n_bytes += ft_strlen(str);

    ft_putstr(str);
}

void    ft_print_number(t_arg *arg)
{
    int num;

    num = va_arg(arg->current, int);
    arg->n_bytes += ft_strlen(ft_itoa(num));

    ft_putnbr(num);
}

int     ft_parse(t_arg *arg, char *format, int index)
{
    while (ft_strchr("%sSpdDioOuUxXcC", format[index]) == NULL)
    {
        switch (format[index])
        {
            case '-':
                arg->flags->dash = 1;
                break;
            case '%':
                arg->flags->percent = 1;
                break;
            case '.':
                arg->flags->point = 1;
                break;
            case '+':
                arg->flags->sign = 1;
                break;
            case ' ':
                arg->flags->space = 1;
                break;
            case '0':
                arg->flags->zero_padding = 1;
        }

        index++;
    }

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
    }

    return (++index);
}

int	    ft_printf(char *format, ...)
{
	int		i;
    int     n;
    t_arg   *arg;

    arg = (t_arg*)malloc(sizeof(t_arg));
    arg->flags = (t_flag*)malloc(sizeof(t_flag));

    i = 0;

    if (!arg || !arg->flags)
    {
        return (-1);
    }

    ft_initiate(arg);
	va_start(arg->current, format);

	while (format[i])
	{
		if (format[i] == '%') {
			i = ft_parse(arg, format, i + 1);
		} else {
            ft_putchar(format[i]);
            i++;
        }
	}

    n = arg->n_bytes;
	va_end(arg->current);
    free(arg->flags);
    free(arg);

	return (n);
}

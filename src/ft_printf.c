#include "ft_printf.h"

t_arg   *ft_initiate(t_arg *tmp)
{
    tmp->width = 0;
    tmp->max_width = 0;
    tmp->flags->dash = 0;
    tmp->flags->point = 0;
    tmp->flags->sign = 0;
    tmp->flags->space = 0;
    tmp->flags->zero = 0;
    tmp->flags->zero_padding = 0;
    tmp->flags->h = 0;
    tmp->flags->l = 0;
    tmp->flags->j = 0;
    tmp->flags->z = 0;

    return (tmp);
}

int     ft_parse(t_arg *arg, const char *format, int index)
{
    while (ft_strchr("%sSpdDioOuUxXcC", format[index]) == NULL)
    {
        ft_get_modifiers(arg, format, index);
        ft_get_width(arg, format, index);
        ft_get_flags(arg, format, index);

        index++;
    }

    return ft_get_conversion(arg, format, index);
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
    arg->n_bytes = 0;

	va_start(arg->current, format);

	while (format[i])
	{
        if (format[i] == '%') {
			i = ft_parse(arg, format, i + 1);
            ft_initiate(arg);
		} else {
            ft_put_char(arg, format[i]);
            i++;
        }
	}

    n = arg->n_bytes;
	va_end(arg->current);

    free(arg->flags);
    free(arg);

	return (n);
}

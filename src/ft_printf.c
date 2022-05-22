/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavalac <apavalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:09:32 by apavalac          #+#    #+#             */
/*   Updated: 2022/05/22 19:28:19 by apavalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_printf.h>

int	ft_printf(char *format, ...)
{
	if (*format == '\0')
	{
		ft_putchar('C');
		return (-1);
	}

	return (0);
}
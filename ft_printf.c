/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:19:47 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/06 02:52:42 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print2(va_list args, const char *s, int i)
{
	int	len;

	len = 0;
	if (s[i] == '%')
		len += ft_putchar(s[i]);
	else if (s[i] == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (s[i] == 'd' || s[i] == 'i')
		len += ft_putint(va_arg(args, int));
	else if (s[i] == 's')
		len += ft_putstr(va_arg(args, char *));
	else
		len += ft_putchar(s[i]);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ')
				i++;
			if (!str[i])
				return (len);
			len += ft_print2(args, str, i);
		}
		i++;
	}
	va_end(args);
	return (len);
}

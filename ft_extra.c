/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:01:14 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/06 03:20:35 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	while (*s)
	{
		len += ft_putchar(*s);
		s++;
	}
	return (len);
}

int	ft_putint(int nbr)
{
	unsigned int	unbr;
	int				len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		unbr = (unsigned int)(nbr * -1);
	}
	else
		unbr = (unsigned int)nbr;
	if (unbr > 9)
		len += ft_putint(unbr / 10);
	len += ft_putchar(unbr % 10 + 48);
	return (len);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

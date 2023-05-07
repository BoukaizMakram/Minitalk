/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:56:48 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/06 05:21:58 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i++])
	{
		if (str[i - 1] < '0' || str[i - 1] > '9')
			return (-1);
		else
			result = result * 10 + (str[i - 1] - '0');
	}
	return (result * sign);
}

void	send_bit(int pid, int bit)
{
	if (bit)
	{
		if (kill(pid, SIGUSR1) == -1)
			return ;
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			return ;
	}
	usleep(700);
}

void	send_server(int pid, char *str)
{
	int	i;
	int	bits;

	i = 0;
	while (str[i])
	{
		bits = 8;
		while (--bits >= 0)
		{
			send_bit(pid, (str[i] >> bits) & 1);
		}
		usleep(700);
		i++;
	}
	i = 8;
	while (i--)
	{
		send_bit(pid, 0);
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3 || !ft_strlen(av[2]))
	{
		ft_printf("FORMAT IS INCORECT\n");
		return (0);
	}
	if (ft_atoi(av[1]) <= 0)
		return (0);
	send_server(ft_atoi(av[1]), av[2]);
	return (0);
}

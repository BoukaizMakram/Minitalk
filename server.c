/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:34:38 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/06 03:39:39 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>

void	action(int signal, siginfo_t *get_info, void *ptr)
{
	static char	c = 0;
	static int	i = 0;
	static int	pid = 0;

	(void)ptr;
	if (get_info->si_pid != pid)
	{
		pid = get_info->si_pid;
		c = 0;
		i = 0;
	}
	c = c | (signal == SIGUSR1);
	if (++i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("%d", getpid());
	ft_printf("\n");
	sig.sa_sigaction = action;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
	{
		pause();
	}
	return (0);
}

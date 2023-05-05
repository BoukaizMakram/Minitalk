#include <stdio.h>
#include "printf/ft_printf.h"
#include <signal.h>

void action(int signal, siginfo_t *get_info, void *ptr)
{
	(void)ptr;
	static char c = 0;
	static int i = 0;
	static int pid = 0;
	if(get_info->si_pid != pid)
	{
		pid = get_info->si_pid;
		c = 0;
		i = 0;
	}
	if(signal == SIGUSR1)
	{
		c = c | 1;
	}
	else if (signal == SIGUSR2)
	{
		c = c | 0;
	}
	i++;
	if(i == 8)
	{
		if(!c)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
		write(1, &c, 1);
		kill(pid, SIGUSR1);
		c = 0;
		i = 0;}
	}
	else
		c = c << 1;
}

int main()
{
	struct sigaction	sig;

	ft_printf("%d", getpid());
	ft_printf("\n");
	sig.sa_sigaction = action;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while(1)
	{
		pause();
	}
	return 0;
}
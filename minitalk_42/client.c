#include "printf/ft_printf.h"
#include <signal.h>

int received = 0;
int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;
    int i = 0;

	negative = 1;
	res = 0;
    while(str[i])
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
            return -1;
        i++;
    }
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
    
	return (res * negative);
}

void send_server(int pid, char *str)
{
    int i;
    int bits;

    i = 0;
    while(str[i])
    {
        bits = 7;
        while(bits >= 0)
        {
            if (str[i] >> bits & 1)
            {
                if(kill(pid, SIGUSR1) == -1)
                return ;
            }
            else
            {
                if(kill(pid, SIGUSR2) == -1)
                return ;
            }
            bits--;
            usleep(700);
        }
        usleep(700);
        i++;
    }
    i = 8;
    while(i)
    {
        kill(pid, SIGUSR2);
        i--;
        usleep(200);
    }
}

void sig_action(int signal, siginfo_t *info,void *v)
{
    (void)info;
    (void)v;
    if(signal == SIGUSR1)
    {
        received++;
    }
    if(signal == SIGUSR2)
    {
        
        ft_printf("Received : %d\n", received);
    }
}

int main(int ac, char **av)
{
    struct sigaction sig;
    sig.sa_sigaction = sig_action;
    sig.sa_flags = SA_SIGINFO;
    if (ac != 3 || !ft_strlen(av[2]))
	{
		ft_printf("FORMAT IS INCORECT");
		return (0);
	}
    if (ft_atoi(av[1]) <= 0)
        return 0;
    sigaction(SIGUSR1, &sig, 0);
    sigaction(SIGUSR2, &sig, 0);
    ft_printf("Sent: %d\n", ft_strlen(av[2]));
    send_server(ft_atoi(av[1]), av[2]);
}

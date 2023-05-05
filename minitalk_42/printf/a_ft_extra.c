#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
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

int	ft_putuint(unsigned int ui)
{
	int	len;

	len = 0;
	if (ui > 9)
	{
		len += ft_putuint(ui / 10);
	}
	len += ft_putchar((ui % 10) + 48);
	return (len);
}

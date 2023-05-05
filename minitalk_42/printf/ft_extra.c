#include "ft_printf.h"

int ft_puthex(unsigned long nbr)
{
    char hex[16] = "0123456789abcdef";
    int len = 0;
    if (nbr >= 16)
    {
        len += ft_puthex(nbr / 16);
        len += ft_puthex(nbr % 16);
    }
    else if(nbr < 16)
        len += ft_putchar(hex[nbr]);
    return (len);
}

int ft_putuphex(unsigned long nbr)
{
    char hex[16] = "0123456789ABCDEF";
    int len = 0;

    if (nbr >= 16)
    {
        len += ft_puthex(nbr / 16);
        len += ft_puthex(nbr % 16);
    }
    else if(nbr < 16)
        len += ft_putchar(hex[nbr]);
    return (len);
}

int ft_putptr(void* ptr)
{
    int len = 0;
    len += ft_putstr("0x");
    len += ft_puthex((unsigned long)ptr);
    return len;
}
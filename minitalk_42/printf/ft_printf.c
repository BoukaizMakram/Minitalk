#include "ft_printf.h"



int ft_printf(char *str, ...)
{
    int len = 0;
    int i = 0;
    va_list args;
    va_start (args, str);

    while (str[i])
    {
        if (str[i] != '%')
        {
            len += ft_putchar(str[i]);
            i++;   
        }
        else
        {
            i++;
            if(str[i] == ' ')
            {
                while(str[i] == ' ')
                    i++;

                if (str[i] != '%' && str[i])
                    len += ft_putchar(' ');
                if(!str[i])
                    return (-1);
            }
            if (!str[i])
                return (len);
            else if(str[i] == 'c')
            {
                len += ft_putchar(va_arg(args, int));
                i++;
            }
            else if(str[i] == 's')
            {
                len += ft_putstr(va_arg(args, char*));
                i++;
            }else if(str[i] == 'p')
            {
                len += ft_putptr(va_arg(args, void*));
                i++;
            }
            else if(str[i] == 'd' || str[i] == 'i')
            {
                len += ft_putint(va_arg(args, int));
                i++;
            }else if(str[i] == 'u')
            {
                len += ft_putuint(va_arg(args, unsigned int));
                i++;
            }else if (str[i] == 'x')
            {
                len += ft_puthex(va_arg(args, unsigned int));
                i++;
            }else if (str[i] == 'X')
            {
                len += ft_puthex(va_arg(args, unsigned int));
                i++;
            }else if(str[i] == '%')
            {
                len += ft_putchar(str[i++]);
            }
        }
    }
    va_end (args);
    return (len);
}
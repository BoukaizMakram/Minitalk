#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_printf(char *str, ...);

int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putint(int i);
int ft_putuint(unsigned int i);
int ft_puthex(unsigned long nbr);
int ft_putuphex(unsigned long nbr);
int ft_putptr(void* ptr);
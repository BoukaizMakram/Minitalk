#include "ft_printf.h"

int main()
{
	int i = 2147483648;

	ft_printf("%d\n", i);
	printf("%d\n", i);
	// ft_printf("%p\n", i);
	// ft_printf("%c\n", i);
	// ft_printf("%% %% %% \n");
	// ft_printf("%X\n", i);
	// ft_printf("%x\n", i);
}
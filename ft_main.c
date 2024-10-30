
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char *hello = "fgth";

	printf("%d\n", printf("%s\n", hello));
	ft_printf("%d\n", ft_printf("%s\n", hello));

	/*
	int	count;
	count = 0;
	ft_putbin(2, &count);
    ft_putchar('\n', &count);
    count = 0;
    ft_putbin(5, &count);
    ft_putchar('\n', &count);
    count = 0;
    ft_putbin(10, &count);
    ft_putchar('\n', &count);
    count = 0;
    ft_putbin(255, &count);
    ft_putchar('\n', &count);*/
	return (0);
}
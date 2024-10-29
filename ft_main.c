
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char *hello = "fgth";

	printf("%d\n", printf("%s\n", hello));
	ft_printf("%d\n", ft_printf("%s\n", hello));
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:43:42 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/29 16:54:43 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_puthexa(unsigned int n, int *count, char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n > 15)
		ft_puthexa(n / 16, count, c);
	ft_putchar(base[n % 16], count);
}
void	ft_putadd(unsigned long int n, int *count)
{
	char	*base;

	if (n == NULL)
		ft_putstr("(nil)", count);
	base = "0123456789abcdef";
	if (n > 15)
		ft_putadd(n / 16, count);
	ft_putchar(base[n % 16], count);
}

void	ft_flags(va_list args, char c, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'x' || c == 'X')
		ft_puthexa(va_arg(args, unsigned int), count, c);
	else if (c == '%')
		ft_putchar('%', count);
	else if (c == 'u')
		ft_putuns(va_arg(args, unsigned int), count);
	else if (c == 'p')
	{
		ft_putstr("0x", count);
		ft_putadd(va_arg(args, unsigned long int), count);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			i++;
			ft_flags(args, str[i], &count);
		}
		else
		{
			count += write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}

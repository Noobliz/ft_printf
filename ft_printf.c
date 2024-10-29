/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisux <lisux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:43:42 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/29 10:20:44 by lisux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	ft_flags(va_list args, char c, int count)
{
	if (c == 'c')
		ft_putchar(va_args(args, int), &count);
	else if (c == 's')
		ft_putstr(va_args(args, char *), &count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_args(args, int), &count);
	else if (c == 'x')
		ft_puthexa_l(va_args(args, unsigned int), &count);
	
}

void	ft_putchar(char c, int count)
{
	count += write(1, &c, 1);
}
void	ft_putstr(char *str, int count)
{
	int	i;

	if (str == NULL)
		return ;
	while (str[i])
	{
		ft_putchar(str[i], &count);
		i++;
	}
}
void	ft_putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", &count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', &count);
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr(n / 10, &count);
	ft_putchar(n % 10 + '0', &count);
}
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	if (!str)
		return (0);
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
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("byuyifyif");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:03:45 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/29 16:18:36 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>

void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putuns(unsigned int n, int *count);
void	ft_puthexa(unsigned int n, int *count, char c);
void	ft_putadd(unsigned long int n, int *count);
int	ft_printf(const char *str, ...);
int	main(void);

#endif
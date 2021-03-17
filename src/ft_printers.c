/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printers.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 08:40:45 by ikole         #+#    #+#                 */
/*   Updated: 2019/12/06 08:40:46 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_putchar(const char c)
{
	write(1, &c, 1);
}

void		ft_putstr_nf(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static void	actual_putstr(const char *str, t_flags *flags, int precision)
{
	int i;

	i = 0;
	if (flags->dot == 1)
	{
		while (str[i] && precision)
		{
			write(1, &str[i], 1);
			i++;
			precision--;
		}
	}
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

void		ft_putstr(const char *str, t_flags *flags, int precision)
{
	if (!str)
	{
		if (flags->dot && flags->precision < 6)
			write(1, "(null)", flags->precision);
		else
			write(1, "(null)", 6);
		return ;
	}
	actual_putstr(str, flags, precision);
}

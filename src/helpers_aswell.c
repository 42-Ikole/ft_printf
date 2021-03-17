/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers_aswell.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 15:41:09 by ikole         #+#    #+#                 */
/*   Updated: 2020/01/03 15:41:10 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_widestrlen(wchar_t *str, t_flags *flags)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((!str && flags->dot && flags->precision > 6) || (!str && !flags->dot))
		return (6);
	else if (!str && flags->dot)
		return (flags->precision);
	while (*str && !flags->dot)
	{
		i += ft_widecharlen(*str);
		str++;
	}
	while (*str && flags->dot && i < flags->precision)
	{
		j = ft_widecharlen(*str);
		if (i + j > flags->precision)
			break ;
		i += j;
		str++;
	}
	return (i);
}

int	ft_widecharlen(wint_t wc)
{
	if (wc <= 0x7F)
		return (1);
	else if (wc <= 0x7FF)
		return (2);
	else if (wc <= 0xFFFF)
		return (3);
	else
		return (4);
}

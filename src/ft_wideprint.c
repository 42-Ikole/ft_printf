/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wideprint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 13:54:28 by ikole         #+#    #+#                 */
/*   Updated: 2020/01/03 13:54:29 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	actual_widestr(wchar_t *str, t_flags *flags, int precision)
{
	int i;
	int printed;

	i = 0;
	printed = 0;
	if (flags->dot)
	{
		while (str[i] && printed != precision)
		{
			ft_widechar(str[i]);
			printed += ft_widecharlen(str[i]);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_widechar(str[i]);
			i++;
		}
	}
}

void		ft_widestr(wchar_t *str, t_flags *flags, int precision)
{
	if (!str)
	{
		if (flags->dot && flags->precision < 6)
			write(1, "(null)", flags->precision);
		else
			write(1, "(null)", 6);
		return ;
	}
	precision = ft_widestrlen(str, flags);
	actual_widestr(str, flags, precision);
}

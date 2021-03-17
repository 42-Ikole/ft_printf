/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_helpers.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 11:24:47 by ikole         #+#    #+#                 */
/*   Updated: 2019/12/06 11:24:57 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_num(long long nbr, t_flags *flags)
{
	int					sgn;
	unsigned long long	res;

	sgn = 1;
	if (nbr < 0)
		sgn = -1;
	res = nbr * sgn;
	return (ft_numlen(res, flags));
}

int		ft_hexlen(unsigned long n, t_flags *flags)
{
	int count;

	if (n == 0 && flags->dot && !flags->precision)
		return (0);
	else if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int		ft_hexlen_prec(unsigned long n, t_flags *flags)
{
	int count;

	count = 0;
	if (n == 0 && flags->dot && flags->precision == 0)
		count--;
	if (n == 0)
		count++;
	else if (flags->hashtag)
		count += 2;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	if (count < flags->precision)
		return (flags->precision);
	return (count);
}

t_bool	ft_exception(t_flags *flags, int sgn)
{
	return (flags->space && sgn == 1 &&
		!(flags->min_width > flags->precision && flags->dot && !flags->minus));
}

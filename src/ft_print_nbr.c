/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_nbr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 13:33:14 by ikole         #+#    #+#                 */
/*   Updated: 2019/12/30 13:33:15 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		ft_putnbr
	(unsigned long long nbr, t_flags *flags, int initial_length)
{
	char	print;
	int		length;

	length = ft_ullen(nbr);
	if (nbr > 9)
		ft_putnbr(nbr / 10, flags, initial_length);
	print = nbr % 10 + 48;
	write(1, &print, 1);
	if (flags->apostrophe && length % 3 == initial_length % 3 && \
	length != initial_length)
	{
		write(1, ".", 1);
		if (!(flags->min_width >= initial_length + (initial_length / 3)))
			flags->printed++;
	}
}

static void		ft_nbr_initializer
	(int *plen, int *length, int initial_length, t_flags *flags)
{
	if (flags->apostrophe)
	{
		if (*length % 3 != 0 && initial_length > 3)
			*length = *length + (*length / 3);
		else if (*length % 3 == 0 && initial_length > 3)
			*length = *length + ((*length / 3) - 1);
	}
	if (*length < flags->precision)
		*plen = flags->precision;
	else
		*plen = *length;
}

static void		ft_nbr_flags_too
	(unsigned long long nbr, t_flags *flags, int length, int sgn)
{
	int plen;
	int initial_length;

	initial_length = length;
	ft_nbr_initializer(&plen, &length, initial_length, flags);
	if (ft_exception(flags, sgn))
	{
		flags->min_width--;
		write(1, " ", 1);
	}
	if (flags->min_width > plen && !flags->zero && !flags->minus)
		ft_whitespace(' ', flags->min_width - plen);
	if (sgn == -1)
		write(1, "-", 1);
	else if (flags->plus)
		write(1, "+", 1);
	if (flags->min_width > plen && flags->zero && !flags->minus)
		ft_whitespace('0', flags->min_width - plen);
	if (plen > length)
		ft_whitespace('0', plen - length);
	if (length > 0)
		ft_putnbr(nbr, flags, initial_length);
	if (flags->min_width > plen && flags->minus)
		ft_whitespace(' ', flags->min_width - plen);
}

void			ft_nbr_flags
	(unsigned long long nbr, t_flags *flags, int length, int sgn)
{
	int plen;

	if (length < flags->precision)
		plen = flags->precision;
	else
		plen = length;
	if (flags->min_width > plen)
		flags->printed = flags->min_width;
	else if (flags->space)
		flags->printed++;
	else
	{
		flags->printed = plen;
		if (flags->plus || sgn == -1)
			flags->printed++;
	}
	if (sgn == -1 || flags->plus)
		flags->min_width--;
	if (flags->dot && flags->min_width && flags->zero)
		flags->zero = 0;
	ft_nbr_flags_too(nbr, flags, length, sgn);
}

void			ft_nbr(long long nbr, t_flags *flags)
{
	unsigned long long	res;
	int					sgn;

	sgn = 1;
	if (nbr < 0)
		sgn = -1;
	res = nbr * sgn;
	ft_nbr_flags(res, flags, ft_num(nbr, flags), sgn);
}

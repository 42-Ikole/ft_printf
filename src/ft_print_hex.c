/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 13:28:55 by ikole         #+#    #+#                 */
/*   Updated: 2019/12/30 13:28:56 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	len_changer
	(int *length, t_flags *flags, int *plen, unsigned long nbr)
{
	if (flags->min_width && flags->dot)
		flags->zero = 0;
	if (flags->precision > *length)
		*plen = flags->precision;
	else
		*plen = *length;
	if (flags->hashtag && nbr != 0)
		*plen += 2;
}

void		ft_puthex(unsigned long nbr, int upper)
{
	float	remainder;
	char	print;

	if (nbr > 15)
		ft_puthex(nbr / 16, upper);
	remainder = nbr % 16;
	if (remainder < 10)
		print = remainder + 48;
	else
		print = remainder + upper;
	write(1, &print, 1);
}

void		ft_putx_flag(unsigned long nbr, int upper, t_flags *flags)
{
	int length;
	int plen;

	length = ft_hexlen(nbr, flags);
	plen = 0;
	len_changer(&length, flags, &plen, nbr);
	if (flags->min_width > plen && !flags->zero && !flags->minus)
		ft_whitespace(' ', flags->min_width - plen);
	if (flags->hashtag && nbr != 0 && upper == 87)
		write(1, "0x", 2);
	else if (flags->hashtag && nbr != 0 && upper == 55)
		write(1, "0X", 2);
	if (flags->min_width > plen && flags->zero && !flags->minus)
		ft_whitespace('0', flags->min_width - plen);
	if (length < flags->precision)
		ft_whitespace('0', flags->precision - length);
	if (!(flags->dot && !flags->precision && !nbr))
		ft_puthex(nbr, upper);
	if (flags->min_width > plen && flags->minus)
		ft_whitespace(' ', flags->min_width - plen);
}

void		ft_putloc(unsigned long loc, t_flags *flags)
{
	write(1, "0x", 2);
	if (loc)
		ft_puthex(loc, 87);
	else if (flags->dot && !flags->precision)
		return ;
	else
		write(1, "0", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_widechar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 10:35:31 by ikole          #+#    #+#                */
/*   Updated: 2020/01/08 14:16:54 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_widechar_4b(wint_t wc)
{
	char str[4];

	str[0] = 0xF0 | ((wc >> 18));
	str[1] = 0x80 | ((wc >> 12) & 0x3F);
	str[2] = 0x80 | ((wc >> 6) & 0x3F);
	str[3] = 0x80 | (wc & 0x3F);
	write(1, str, 4);
}

static void	ft_widechar_3b(wint_t wc)
{
	char str[3];

	str[0] = 0xE0 | ((wc >> 12));
	str[1] = 0x80 | ((wc >> 6) & 0x3F);
	str[2] = 0x80 | (wc & 0x3F);
	write(1, str, 3);
}

static void	ft_widechar_2b(wint_t wc)
{
	char str[2];

	str[0] = 0xC0 | ((wc >> 6));
	str[1] = 0x80 | (wc & 0x3F);
	write(1, str, 2);
}

void		ft_widechar(wint_t wc)
{
	if (wc <= 0x7F)
		write(1, &wc, 1);
	else if (wc <= 0x7FF)
		ft_widechar_2b(wc);
	else if (wc <= 0xFFFF)
		ft_widechar_3b(wc);
	else
		ft_widechar_4b(wc);
}

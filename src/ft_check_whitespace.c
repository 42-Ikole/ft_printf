/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_whitespace.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 12:49:53 by ikole         #+#    #+#                 */
/*   Updated: 2019/12/30 12:49:54 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_check_whitespace(t_flags *flags, const char conversion, int *printlen)
{
	int whitespace;

	whitespace = 0;
	if (conversion == 'n')
		return (whitespace);
	if (flags->precision && ft_strnstr(conversion, "xXu"))
		flags->zero = 0;
	if (*printlen < flags->min_width && !ft_strnstr(conversion, "diuxX"))
	{
		whitespace += flags->min_width - *printlen;
		*printlen = flags->min_width;
	}
	if (flags->min_width < *printlen)
		flags->printed = *printlen;
	else
		flags->printed = flags->min_width;
	return (whitespace);
}

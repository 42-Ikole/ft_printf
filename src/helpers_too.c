/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers_too.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 16:12:22 by ikole         #+#    #+#                 */
/*   Updated: 2019/12/30 16:12:23 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_strnstr(const char check, const char *needle)
{
	int i;

	i = 0;
	while (needle[i])
	{
		if (check == needle[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_whitespace(const char c, int len)
{
	while (len > 0)
	{
		write(1, &c, 1);
		len--;
	}
}

int		ft_strlen(const char *str, t_flags *flags)
{
	int i;
	int precision;

	if (!str)
		return ((flags->precision < 6 && flags->dot) ? flags->precision : 6);
	i = 0;
	precision = flags->precision;
	if (flags->dot == 1)
	{
		while (str[i] && precision)
		{
			i++;
			precision--;
		}
	}
	else
		while (str[i])
			i++;
	return (i);
}

int		ft_ullen(unsigned long long nbr)
{
	int i;

	i = 0;
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

int		ft_numlen(unsigned long long nbr, t_flags *flags)
{
	int length;

	length = 0;
	if (nbr == 0)
		length++;
	if (flags->dot && !flags->precision && nbr == 0)
		length--;
	while (nbr > 0)
	{
		length++;
		nbr /= 10;
	}
	return (length);
}

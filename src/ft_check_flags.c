/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_flags.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 11:31:47 by ikole         #+#    #+#                 */
/*   Updated: 2019/12/30 11:31:54 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	flag_finder(int i, t_flags *flags, const char *input)
{
	while (ft_strnstr(input[i], "+- #0'"))
	{
		if (input[i] == '-')
			flags->minus = 1;
		else if (input[i] == '+')
		{
			flags->space = 0;
			flags->plus = 1;
		}
		else if (input[i] == ' ' && !flags->plus)
			flags->space = 1;
		else if (input[i] == '#')
			flags->hashtag = 1;
		else if (input[i] == '\'')
			flags->apostrophe = 1;
		else if (input[i] == '0')
			flags->zero = 1;
		i++;
	}
	return (i);
}

static int	precision(int i, t_flags *flags, const char *input, va_list arg)
{
	while (ft_strnstr(input[i], ".0123456789*"))
	{
		if (input[i] >= '0' && input[i] <= '9' && input[i - 1] != '.')
		{
			flags->min_width = ft_atoi(&input[i]);
			while (input[i] >= '0' && input[i] <= '9')
				i++;
			i--;
		}
		else if (input[i] == '*' && input[i - 1] != '.')
			flags->min_width = va_arg(arg, int);
		else if (input[i] == '.')
			flags->dot = 1;
		else if (input[i] >= '0' && input[i] <= '9' && input[i - 1] == '.')
		{
			flags->precision = ft_atoi(&input[i]);
			while (input[i] >= '0' && input[i] <= '9')
				i++;
			i--;
		}
		else if (input[i] >= '*' && input[i - 1] == '.')
			flags->precision = va_arg(arg, int);
		i++;
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	long long res;
	long long sgn;

	res = 0;
	sgn = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
		sgn = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		if ((res * 10 + (*str - '0')) < res)
			return (((sgn * -1) - 1) / 2);
		res = res * 10 + *str - '0';
		str++;
	}
	return ((int)(res * sgn));
}

static int	modifiers(int i, t_flags *flags, const char *input)
{
	while (ft_strnstr(input[i], "lh"))
	{
		if (input[i] == 'l' && input[i - 1] != 'l')
			flags->l = 1;
		else if (input[i] == 'l' && input[i - 1] == 'l')
		{
			flags->l = 0;
			flags->ll = 1;
		}
		else if (input[i] == 'h' && input[i - 1] != 'h')
			flags->h = 1;
		else if (input[i] == 'h' && input[i - 1] == 'h')
		{
			flags->h = 0;
			flags->hh = 1;
		}
		i++;
	}
	return (i);
}

int			ft_check_flags
	(t_flags *flags, const char *input, int i, va_list arg)
{
	i = flag_finder(i, flags, input);
	i = precision(i, flags, input, arg);
	i = modifiers(i, flags, input);
	if (flags->min_width < 0)
	{
		flags->minus = 1;
		flags->min_width *= -1;
	}
	ft_conversions(input[i], flags, arg);
	return (i);
}

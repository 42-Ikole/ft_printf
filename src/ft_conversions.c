/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conversions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 12:54:33 by ikole          #+#    #+#                */
/*   Updated: 2020/01/08 13:37:21 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	conv_npc(const char conversion, t_flags *flags, void *p_arg)
{
	if (conversion == 'c' && flags->l)
		ft_widechar((wint_t)p_arg);
	else if (conversion == 'c')
		ft_putchar((const char)p_arg);
	else if (conversion == 's' && flags->l)
		ft_widestr((wchar_t*)p_arg, flags, flags->precision);
	else if (conversion == 's')
		ft_putstr((const char*)p_arg, flags, flags->precision);
	else if (conversion == 'p')
		ft_putloc((unsigned long)p_arg, flags);
	else if (conversion == 'n' && flags->l)
		ft_fillvar_l(p_arg, flags);
	else if (conversion == 'n' && flags->ll)
		ft_fillvar_ll(p_arg, flags);
	else if (conversion == 'n' && flags->h)
		ft_fillvar_h(p_arg, flags);
	else if (conversion == 'n' && flags->hh)
		ft_fillvar_hh(p_arg, flags);
	else if (conversion == 'n')
		ft_fillvar_i(p_arg, flags);
}

static void	conv_nbr(const char conversion, t_flags *flags, void *p_arg)
{
	if ((conversion == 'd' || conversion == 'i') && flags->l)
		ft_nbr((long)p_arg, flags);
	else if ((conversion == 'd' || conversion == 'i') && flags->ll)
		ft_nbr((long long)p_arg, flags);
	else if ((conversion == 'd' || conversion == 'i') && flags->h)
		ft_nbr((short)p_arg, flags);
	else if ((conversion == 'd' || conversion == 'i') && flags->hh)
		ft_nbr((signed char)p_arg, flags);
	else if (conversion == 'd' || conversion == 'i')
		ft_nbr((int)p_arg, flags);
	else if (conversion == 'u' && flags->l)
		ft_nbr_flags((unsigned long)p_arg, flags, \
		ft_numlen((unsigned long)p_arg, flags), 1);
	else if (conversion == 'u' && flags->ll)
		ft_nbr_flags((unsigned long long)p_arg, flags, \
		ft_numlen((unsigned long long)p_arg, flags), 1);
	else if (conversion == 'u' && flags->h)
		ft_nbr_flags((unsigned short)p_arg, flags, \
			ft_numlen((unsigned short)p_arg, flags), 1);
	else if (conversion == 'u' && flags->hh)
		ft_nbr_flags((unsigned char)p_arg, flags, \
			ft_numlen((unsigned char)p_arg, flags), 1);
	else if (conversion == 'u')
		ft_nbr_flags((unsigned int)p_arg, flags, \
			ft_numlen((unsigned int)p_arg, flags), 1);
}

static void	conv_hex(const char conversion, t_flags *flags, void *p_arg)
{
	if (conversion == 'x' && flags->l)
		ft_putx_flag((unsigned long)p_arg, 87, flags);
	else if (conversion == 'x' && flags->ll)
		ft_putx_flag((unsigned long long)p_arg, 87, flags);
	else if (conversion == 'x' && flags->h)
		ft_putx_flag((unsigned short)p_arg, 87, flags);
	else if (conversion == 'x' && flags->hh)
		ft_putx_flag((unsigned char)p_arg, 87, flags);
	else if (conversion == 'x')
		ft_putx_flag((unsigned int)p_arg, 87, flags);
	else if (conversion == 'X' && flags->l)
		ft_putx_flag((unsigned long)p_arg, 55, flags);
	else if (conversion == 'X' && flags->ll)
		ft_putx_flag((unsigned long long)p_arg, 55, flags);
	else if (conversion == 'X' && flags->h)
		ft_putx_flag((unsigned short)p_arg, 55, flags);
	else if (conversion == 'X' && flags->hh)
		ft_putx_flag((unsigned char)p_arg, 55, flags);
	else if (conversion == 'X')
		ft_putx_flag((unsigned int)p_arg, 55, flags);
}

int			ft_conversions(char conversion, t_flags *flags, va_list arg)
{
	void	*p_arg;
	int		printlen;
	int		whitespace;

	if (conversion == '%')
	{
		p_arg = (void*)'%';
		conversion = 'c';
	}
	else
		p_arg = va_arg(arg, void*);
	printlen = ft_printlen(conversion, p_arg, flags);
	whitespace = ft_check_whitespace(flags, conversion, &printlen);
	if (flags->zero && whitespace > 0 && \
	!flags->minus && !ft_strnstr(conversion, "diuxXn"))
		ft_whitespace('0', whitespace);
	else if (!flags->zero && whitespace > 0 && \
	!flags->minus && !ft_strnstr(conversion, "diuxXn"))
		ft_whitespace(' ', whitespace);
	conv_npc(conversion, flags, p_arg);
	conv_nbr(conversion, flags, p_arg);
	conv_hex(conversion, flags, p_arg);
	if (whitespace > 0 && flags->minus && conversion != 'n')
		ft_whitespace(' ', whitespace);
	return (printlen);
}

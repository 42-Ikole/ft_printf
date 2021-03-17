/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 16:13:37 by ikole         #+#    #+#                 */
/*   Updated: 2019/12/30 16:13:37 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	nbrlen(const char conversion, void *p_arg, t_flags *flags)
{
	if ((conversion == 'd' || conversion == 'i') && flags->l)
		return (ft_num((long)p_arg, flags));
	else if ((conversion == 'd' || conversion == 'i') && flags->ll)
		return (ft_num((long long)p_arg, flags));
	else if ((conversion == 'd' || conversion == 'i') && flags->h)
		return (ft_num((short)p_arg, flags));
	else if ((conversion == 'd' || conversion == 'i') && flags->hh)
		return (ft_num((signed char)p_arg, flags));
	else if (conversion == 'd' || conversion == 'i')
		return (ft_num((int)p_arg, flags));
	else if (conversion == 'u' && !flags->l)
		return (ft_numlen((unsigned long)p_arg, flags));
	else if (conversion == 'u' && !flags->ll)
		return (ft_numlen((unsigned long long)p_arg, flags));
	else if (conversion == 'u' && !flags->h)
		return (ft_numlen((unsigned short)p_arg, flags));
	else if (conversion == 'u' && !flags->hh)
		return (ft_numlen((unsigned char)p_arg, flags));
	else if (conversion == 'u')
		return (ft_numlen((unsigned int)p_arg, flags));
	else
		return (0);
}

int			ft_printlen(const char conversion, void *p_arg, t_flags *flags)
{
	if (conversion == 'u')
		flags->plus = 0;
	if (conversion == 's' && flags->l)
		return (ft_widestrlen((wchar_t*)p_arg, flags));
	else if (conversion == 's')
		return (ft_strlen((const char*)p_arg, flags));
	else if (conversion == 'p')
		return (ft_hexlen((unsigned long)p_arg, flags) + 2);
	else if ((conversion == 'x' || conversion == 'X') && flags->l)
		return (ft_hexlen_prec((unsigned long)p_arg, flags));
	else if ((conversion == 'x' || conversion == 'X') && flags->ll)
		return (ft_hexlen_prec((unsigned long long)p_arg, flags));
	else if ((conversion == 'x' || conversion == 'X') && flags->h)
		return (ft_hexlen_prec((unsigned short)p_arg, flags));
	else if ((conversion == 'x' || conversion == 'X') && flags->hh)
		return (ft_hexlen_prec((unsigned char)p_arg, flags));
	else if (conversion == 'x' || conversion == 'X')
		return (ft_hexlen_prec((unsigned long)p_arg, flags));
	else if (conversion == 'c' && flags->l)
		return (ft_widecharlen((wint_t)p_arg));
	else if (conversion == 'c')
		return (1);
	else
		return (nbrlen(conversion, p_arg, flags));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fillvar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 13:27:12 by ikole         #+#    #+#                 */
/*   Updated: 2019/12/30 13:27:13 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_fillvar_l(long *var, t_flags *flags)
{
	if (var)
		*var = flags->until_now_printed;
}

void	ft_fillvar_ll(long long *var, t_flags *flags)
{
	if (var)
		*var = flags->until_now_printed;
}

void	ft_fillvar_h(short *var, t_flags *flags)
{
	if (var)
		*var = flags->until_now_printed;
}

void	ft_fillvar_hh(signed char *var, t_flags *flags)
{
	if (var)
		*var = flags->until_now_printed;
}

void	ft_fillvar_i(int *var, t_flags *flags)
{
	if (var)
		*var = flags->until_now_printed;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:27:59 by ikole         #+#    #+#                 */
/*   Updated: 2019/12/04 16:27:59 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

typedef enum		e_bool
{
	false, true
}					t_bool;

typedef	struct		s_flags
{
	t_bool	minus;
	t_bool	plus;
	t_bool	dot;
	t_bool	space;
	t_bool	zero;
	t_bool	hashtag;
	t_bool	apostrophe;
	t_bool	l;
	t_bool	ll;
	t_bool	h;
	t_bool	hh;
	int		precision;
	int		min_width;
	int		printed;
	int		until_now_printed;
}					t_flags;

int					ft_printf(const char *input, ...);

void				ft_putchar(const char c);
void				ft_widechar(wint_t c);
void				ft_putstr(const char *str, t_flags *flags, int precision);
void				ft_putloc(unsigned long loc, t_flags *flags);
void				ft_nbr(long long nbr, t_flags *flags);
void				ft_nbr_flags(unsigned long long nbr, \
					t_flags *flags, int length, int sgn);
void				ft_putstr_nf(char *str);
void				ft_puthex(unsigned long nbr, int upper);
void				ft_putx_flag(unsigned long nbr, int upper, t_flags *flags);
void				ft_fillvar_l(long *var, t_flags *flags);
void				ft_fillvar_ll(long long *var, t_flags *flags);
void				ft_fillvar_h(short *var, t_flags *flags);
void				ft_fillvar_hh(signed char *var, t_flags *flags);
void				ft_fillvar_i(int *var, t_flags *flags);
int					ft_atoi(const char *str);
int					ft_strlen(const char *str, t_flags *flags);
void				ft_widestr(wchar_t *str, t_flags *flags, int precision);

int					ft_check_flags(t_flags *flags, const char *input, \
					int i, va_list arg);
int					ft_conversions(const char conversion, \
					t_flags *flags, va_list arg);
int					ft_check_whitespace(t_flags *flags, \
					const char conversion, int *printlen);

int					ft_printlen(const char conversion, \
					void *p_arg, t_flags *flags);
void				ft_whitespace(const char c, int len);
int					ft_num(long long nbr, t_flags *flags);
int					ft_numlen(unsigned long long nbr, t_flags *flags);
int					ft_strnstr(const char check, const char *needle);
int					ft_hexlen(unsigned long n, t_flags *flags);
int					ft_ullen(unsigned long long nbr);
int					ft_hexlen_prec(unsigned long n, t_flags *flags);
int					ft_widecharlen(wint_t wc);
int					ft_widestrlen(wchar_t *str, t_flags *flags);
t_bool				ft_exception(t_flags *flags, int sgn);

#endif

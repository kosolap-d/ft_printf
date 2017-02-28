/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:14:50 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/16 15:14:52 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H
# define F format[i]
# define FL f->flag
# define P && format[i] ==
# define IF '0'P'+'P' 'P'-'P'#'
# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flags
{
	char		flag[6];
	int			width;
	int			prec;
	char		modifiers;
	char		type;
}				t_flags;

int				(*funcs_g[128])(va_list, t_flags *);
void			ft_bzero(void *s, size_t n);
void			ft_putnbr(int nb);
char			*ft_strchr(const char *s, int c);
void			*ft_memset(void *b, int c, size_t len);
int				count_nbr(long long int n);
char			*pf_itoa(long long int n, int l, int ch);
char			*pf_itoa_u(size_t num, int len, int ch);
int				ft_pars(char *format, int *j, va_list *arg);
void			fu_width(int *i, int len, char c);
int				flag_i(va_list arg, t_flags *f);
int				flag_dbig(va_list arg, t_flags *f);
int				flag_char(va_list arg, t_flags *f);
int				flag_s(va_list arg, t_flags *f);
int				flag_und(va_list arg, t_flags *f);
int				flag_u(va_list arg, t_flags *f);
int				flag_ubig(va_list arg, t_flags *f);
int				flag_x(va_list arg, t_flags *f);
int				flag_o(va_list arg, t_flags *f);
int				flag_obig(va_list arg, t_flags *f);
int				flag_p(va_list arg, t_flags *f);
long long int	kost(va_list arg, char c);
size_t			kost_x(va_list arg, char c);
int				ft_printf(char *format, ...);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:09:11 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/28 18:09:13 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fu_width(int *i, int len, char c)
{
	while ((*i += 1) < len)
		write(1, &c, 1);
}

void		fu_inti_fu(void)
{
	int		i;

	i = -1;
	while (++i < 128)
		funcs_g[i] = &flag_und;
	funcs_g['i'] = &flag_i;
	funcs_g['d'] = &flag_i;
	funcs_g['D'] = &flag_dbig;
	funcs_g['c'] = &flag_char;
	funcs_g['C'] = &flag_char;
	funcs_g['s'] = &flag_s;
	funcs_g['S'] = &flag_s;
	funcs_g['u'] = &flag_u;
	funcs_g['U'] = &flag_ubig;
	funcs_g['x'] = &flag_x;
	funcs_g['X'] = &flag_x;
	funcs_g['O'] = &flag_obig;
	funcs_g['o'] = &flag_o;
	funcs_g['p'] = &flag_p;
}

int			ft_printf(char *format, ...)
{
	va_list		arg;
	int			i;
	int			res;

	fu_inti_fu();
	i = -1;
	res = 0;
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%')
			res += ft_pars((format + (i += 1)), &i, &arg);
		if (!format[i])
			break ;
		if (format[i] == '%')
		{
			i--;
			continue ;
		}
		write(1, &format[i], 1);
		res++;
	}
	va_end(arg);
	return (res);
}

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
		g_funcs[i] = &flag_und;
	g_funcs['i'] = &flag_i;
	g_funcs['d'] = &flag_i;
	g_funcs['D'] = &flag_dbig;
	g_funcs['c'] = &flag_char;
	g_funcs['C'] = &flag_char;
	g_funcs['s'] = &flag_s;
	g_funcs['S'] = &flag_s;
	g_funcs['u'] = &flag_u;
	g_funcs['U'] = &flag_ubig;
	g_funcs['x'] = &flag_x;
	g_funcs['X'] = &flag_x;
	g_funcs['O'] = &flag_obig;
	g_funcs['o'] = &flag_o;
	g_funcs['p'] = &flag_p;
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

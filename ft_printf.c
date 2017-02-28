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

void	fu_width(int *i, int len, char c)
{
	while ((*i += 1) < len)
		write(1, &c, 1);
}

void	fu_inti(int (*funcs[128])(va_list, struct s_flags *))
{
	int		i;

	i = -1;
	while (++i < 128)
		funcs[i] = &flag_und;
	funcs['i'] = &flag_i;
	funcs['d'] = &flag_i;
	funcs['D'] = &flag_dbig;
	funcs['c'] = &flag_char;
	funcs['C'] = &flag_char;
	funcs['s'] = &flag_s;
	funcs['S'] = &flag_s;
	funcs['u'] = &flag_u;
	funcs['U'] = &flag_ubig;
	funcs['x'] = &flag_x;
	funcs['X'] = &flag_x;
	funcs['O'] = &flag_obig;
	funcs['o'] = &flag_o;
	funcs['p'] = &flag_p;
}

int		ft_printf(char *format, ...)
{
	va_list		arg;
	int			i;
	int			res;
	int			(*funcs[128])(va_list, struct s_flags *);

	i = -1;
	fu_inti(funcs);
	res = 0;
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%')
			res += ft_pars((format + (i += 1)), &i, &arg, funcs);
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

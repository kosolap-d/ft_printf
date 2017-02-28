/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:22:53 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/23 14:22:54 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_modifiers(char *format, int *i, int mod)
{
	int		res;

	res = mod;
	if (format[*i] == 'h' && format[*i + 1] == 'h' && mod < 'a')
	{
		*i += 1;
		res = 'a';
	}
	else if (format[*i] == 'h' && mod < 'b')
		res = 'b';
	else if (format[*i] == 'l' && format[*i + 1] == 'l' && mod < 'd')
	{
		*i += 1;
		res = 'd';
	}
	else if (format[*i] == 'l' && mod < 'c')
		res = 'c';
	else if (format[*i] == 'j' && mod < 'e')
		res = 'e';
	else if (format[*i] == 'z' && mod < 'f')
		res = 'f';
	*i += 1;
	return (res);
}

int		init_flag(t_flags *flags)
{
	ft_memset(flags->flag, 0, 6);
	flags->width = -1;
	flags->prec = -1;
	flags->modifiers = 0;
	flags->type = 'u';
	return (0);
}

int		ft_pars(char *format, int *j, va_list *arg)
{
	t_flags	flags;
	int		i;

	i = init_flag(&flags);
	while (format[i])
	{
		while (ft_strchr("0+ -#", format[i]))
		{
			flags.flag[(format[i] % 6)] = format[i];
			i++;
		}
		if (F >= '0' && F <= '9' && ((flags.width = ft_atoi(format + i)) + 1))
			while (format[i] >= '0' && format[i] <= '9')
				i++;
		if (format[i] == '.' && ((flags.prec = ft_atoi(format + i++ + 1)) + 1))
			while (format[i] >= '0' && format[i] <= '9')
				i++;
		if (F == 'h' || F == 'l' || F == 'z' || F == 'j')
			flags.modifiers = ft_modifiers(format, &i, flags.modifiers);
		if (!ft_strchr("0123456789+. -#lLhzj", format[i]) && (*j += i + 1)
			&& (flags.type = format[i]))
			return (g_funcs[F](*arg, &flags));
	}
	return (0);
}

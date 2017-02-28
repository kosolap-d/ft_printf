/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:58:35 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/23 16:58:37 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	kost(va_list arg, char c)
{
	long long int	res;

	if (c == 'a')
		res = (char)va_arg(arg, int);
	else if (c == 'b')
		res = (short int)va_arg(arg, int);
	else if (c == 'c')
		res = va_arg(arg, long int);
	else if (c == 'd')
		res = va_arg(arg, long long int);
	else if (c == 'e')
		res = va_arg(arg, intmax_t);
	else if (c == 'f')
		res = va_arg(arg, size_t);
	else
		res = va_arg(arg, int);
	return (res);
}

int				flag_i(va_list arg, t_flags *f)
{
	char			*res;
	int				i;
	int				len;
	long long int	var;

	i = -1;
	var = kost(arg, f->modifiers);
	if (f->prec == -1 && f->flag[0] && !f->flag[3])
	{
		if (f->flag[2] || var < 0 || f->flag[1] || f->flag[2])
			res = pf_itoa(var, f->width - 1, (FL[1] > 0 ? FL[1] : FL[2]));
		else
			res = pf_itoa(var, f->width, (FL[1] > 0 ? FL[1] : FL[2]));
	}
	else
		res = pf_itoa(var, f->prec, (FL[1] > 0 ? FL[1] : FL[2]));
	if (!f->prec && !var)
		res[ft_strlen(res) - 1] = f->width > 0 ? ' ' : 0;
	len = ft_strlen(res);
	f->flag[3] != 0 ? write(1, res, len) : fu_width(&i, f->width - len, ' ');
	f->flag[3] == 0 ? write(1, res, len) : fu_width(&i, f->width - len, ' ');
	free(res);
	return (len + i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:05:13 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/23 18:05:26 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	kost_u(va_list arg, char c)
{
	size_t	res;

	if (c == 'a')
		res = (unsigned char)va_arg(arg, int);
	else if (c == 'b')
		res = (unsigned short int)va_arg(arg, int);
	else if (c == 'c')
		res = va_arg(arg, unsigned long int);
	else if (c == 'd')
		res = va_arg(arg, unsigned long long int);
	else if (c == 'e')
		res = va_arg(arg, intmax_t);
	else if (c == 'f')
		res = va_arg(arg, size_t);
	else
		res = va_arg(arg, unsigned int);
	return (res);
}

int		flag_u(va_list arg, t_flags *f)
{
	char	*res;
	int		i;
	int		len;
	size_t	var;

	i = -1;
	var = kost_u(arg, f->modifiers);
	if (f->prec == -1 && f->flag[0] && !f->flag[3])
		res = pf_itoa_u(var, f->width, 0);
	else
		res = pf_itoa_u(var, f->prec, 0);
	if (!f->prec && !var)
		res[ft_strlen(res) - 1] = f->width > 0 ? ' ' : 0;
	len = ft_strlen(res);
	f->flag[3] != 0 ? write(1, res, len) : fu_width(&i, f->width - len, ' ');
	f->flag[3] == 0 ? write(1, res, len) : fu_width(&i, f->width - len, ' ');
	free(res);
	return (len + i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:16:51 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/23 17:17:11 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				flag_s(va_list arg, t_flags *f)
{
	char			*res;
	int				i;
	int				len;
	char			k;

	i = -1;
	if ((res = va_arg(arg, char *)) == 0)
		res = "(null)";
	len = ft_strlen(res);
	if (!f->flag[3])
		k = f->flag[0] != 0 ? '0' : ' ';
	else
		k = ' ';
	if (len > f->prec)
		len = f->prec > -1 ? f->prec : len;
	f->flag[3] != 0 ? write(1, res, len) : fu_width(&i, f->width - len, k);
	f->flag[3] == 0 ? write(1, res, len) : fu_width(&i, f->width - len, k);
	return (len + i);
}

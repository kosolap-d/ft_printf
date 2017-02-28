/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:53:50 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/27 14:54:04 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_o(size_t value, int base)
{
	int	i;

	i = 1;
	while (value /= base)
		i++;
	return (i);
}

static char		*ft_itoa_base_o(size_t value, int base, t_flags *f)
{
	char		*res;
	char		*pat;
	int			len;
	int			sh;

	len = count_o(value, base);
	pat = "0123456789abcdef";
	len = len < f->prec ? f->prec : len;
	if (value)
		sh = f->flag[5] != 0 ? 1 : 0;
	else
		sh = 0;
	if (f->flag[0] && !f->flag[3])
		len = len < f->width ? f->width - sh : len;
	res = (char *)malloc(sizeof(char *) * (len += sh) + 1);
	res[len] = 0;
	while (--len != -1)
	{
		res[len] = pat[value % base];
		value /= base;
	}
	return (res);
}

int				flag_o(va_list arg, t_flags *f)
{
	char			*res;
	int				i;
	int				len;
	size_t			var;

	i = -1;
	var = kost_x(arg, f->modifiers);
	res = ft_itoa_base_o(var, 8, f);
	if (!f->prec && !var)
	{
		if (f->flag[5])
			res[ft_strlen(res) - 1] = f->width > 0 ? ' ' : '0';
		else
			res[ft_strlen(res) - 1] = f->width > 0 ? ' ' : 0;
	}
	len = ft_strlen(res);
	f->flag[3] != 0 ? write(1, res, len) : fu_width(&i, f->width - len, ' ');
	f->flag[3] == 0 ? write(1, res, len) : fu_width(&i, f->width - len, ' ');
	free(res);
	return (len + i);
}

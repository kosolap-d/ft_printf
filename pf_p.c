/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:26:35 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/27 17:26:45 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_p(long long int value, int base)
{
	int	i;

	i = 1;
	while (value /= base)
		i++;
	return (i);
}

static char		*ft_itoa_base_p(long long int value, int base, t_flags *f)
{
	char		*res;
	char		*pat;
	int			len;
	int			sh;

	pat = "0123456789abcdef";
	len = count_p(value, base);
	len = len < f->prec ? f->prec : len;
	if (value)
		sh = 2;
	else
		sh = 2;
	if (f->flag[0] && !f->flag[3])
		len = len < f->width ? f->width - sh : len;
	res = (char *)malloc(sizeof(char *) * (len += sh) + 1);
	res[len] = 0;
	while (--len != -1)
	{
		res[len] = pat[value % base];
		value /= base;
	}
	res[1] = 'x';
	return (res);
}

int				flag_p(va_list arg, t_flags *f)
{
	char			*res;
	int				i;
	int				len;
	long long int	var;
	char			k;

	i = -1;
	var = va_arg(arg, long long int);
	res = ft_itoa_base_p(var, 16, f);
	if (!f->prec && !var)
		res[ft_strlen(res) - 1] = f->width > 0 ? ' ' : 0;
	len = ft_strlen(res);
	k = f->flag[0] != 0 ? '0' : ' ';
	if (len > f->prec)
		len = f->prec > len ? f->prec : len;
	f->flag[3] != 0 ? write(1, res, len) : fu_width(&i, f->width - len, k);
	f->flag[3] == 0 ? write(1, res, len) : fu_width(&i, f->width - len, k);
	free(res);
	return (len + i);
}

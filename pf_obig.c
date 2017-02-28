/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_obig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:40:32 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/27 15:40:51 by dkosolap         ###   ########.fr       */
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

size_t			kost_obig(va_list arg, char c)
{
	size_t	res;

	if (c == 'a')
		res = (unsigned short int)va_arg(arg, long int);
	else if (c == 'b')
		res = (unsigned short int)va_arg(arg, unsigned long int);
	else if (c == 'c')
		res = va_arg(arg, unsigned long int);
	else if (c == 'd')
		res = va_arg(arg, unsigned long long int);
	else if (c == 'e')
		res = va_arg(arg, intmax_t);
	else if (c == 'f')
		res = va_arg(arg, size_t);
	else
		res = va_arg(arg, unsigned long int);
	return (res);
}

int				flag_obig(va_list arg, t_flags *f)
{
	char			*res;
	int				i;
	int				len;
	size_t			var;

	i = -1;
	var = kost_obig(arg, f->modifiers);
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

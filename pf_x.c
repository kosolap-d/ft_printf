/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:04:57 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/24 17:05:13 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			kost_x(va_list arg, char c)
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

int				count(size_t value, int base)
{
	int	i;

	i = 1;
	while (value /= base)
		i++;
	return (i);
}

char			*ft_itoa_base_x(size_t value, int base, t_flags *f)
{
	char		*res;
	char		*pat;
	int			len;
	int			sh;

	len = count(value, base);
	len = len < f->prec ? f->prec : len;
	if (value)
		sh = f->flag[5] != 0 ? 2 : 0;
	else
		sh = 0;
	if (f->flag[0] && !f->flag[3])
		len = len < f->width ? f->width - sh : len;
	pat = f->type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	res = (char *)malloc(sizeof(char *) * (len += sh) + 1);
	res[len] = 0;
	while (--len != -1)
	{
		res[len] = pat[value % base];
		value /= base;
	}
	if (sh)
		res[1] = f->type == 'x' ? 'x' : 'X';
	return (res);
}

int				flag_x(va_list arg, t_flags *f)
{
	char			*res;
	int				i;
	int				len;
	size_t			var;

	i = -1;
	var = kost_x(arg, f->modifiers);
	res = ft_itoa_base_x(var, 16, f);
	if (!f->prec && !var)
		res[ft_strlen(res) - 1] = f->width > 0 ? ' ' : 0;
	len = ft_strlen(res);
	f->flag[3] != 0 ? write(1, res, len) : fu_width(&i, f->width - len, ' ');
	f->flag[3] == 0 ? write(1, res, len) : fu_width(&i, f->width - len, ' ');
	free(res);
	return (len + i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:04:35 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/23 17:04:37 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				flag_char(va_list arg, t_flags *f)
{
	int		i;
	char	c;
	char	k;

	i = -1;
	c = (unsigned char)va_arg(arg, int);
	k = f->flag[0] != 0 ? '0' : ' ';
	f->flag[3] != 0 ? write(1, &c, 1) : fu_width(&i, f->width - 1, k);
	f->flag[3] == 0 ? write(1, &c, 1) : fu_width(&i, f->width - 1, k);
	return (1 + i);
}

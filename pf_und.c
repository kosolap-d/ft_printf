/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_und.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:53:52 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/23 18:53:54 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				flag_und(va_list arg, t_flags *f)
{
	int		i;
	char	c;
	char	k;

	i = -1;
	c = f->type;
	if (!f->flag[3])
		k = f->flag[0] != 0 ? '0' : ' ';
	else
		k = ' ';
	f->flag[3] != 0 ? write(1, &c, 1) : fu_width(&i, f->width - 1, k);
	f->flag[3] == 0 ? write(1, &c, 1) : fu_width(&i, f->width - 1, k);
	return (1 + i);
}

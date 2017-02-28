/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:34:27 by dkosolap          #+#    #+#             */
/*   Updated: 2017/02/23 10:34:41 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_nbr_u(size_t n)
{
	int	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char	*pf_itoa_u(size_t n, int l, int ch)
{
	char	*res;

	ch = ch > 0 ? 1 : 0;
	l = l < count_nbr_u(n) ? count_nbr_u(n) : l;
	if (!(res = (char*)malloc((l += ch) + 1)))
		return (NULL);
	res[l] = 0;
	while (l != 0)
	{
		res[--l] = (n % 10) + 48;
		n /= 10;
	}
	if (ch)
		res[0] = '+';
	return (res);
}

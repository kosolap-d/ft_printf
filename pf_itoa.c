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

int				count_nbr(long long int n)
{
	int	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*pf_itoa_m(size_t n, int l)
{
	int		i;
	char	*res;

	l = l < count_nbr(n) ? count_nbr(n) : l;
	if (!(res = (char*)malloc((l += 1) + 1)))
		return (NULL);
	res[l] = 0;
	while (l != 0)
	{
		res[--l] = (n % 10) + 48;
		n /= 10;
	}
	res[0] = '-';
	return (res);
}

char			*pf_itoa(long long int n, int l, int ch)
{
	int		i;
	char	*res;

	i = count_nbr(n);
	l = l < i ? i : l;
	if (n < 0)
		return (pf_itoa_m(-n, l));
	if (!(res = (char*)malloc((l += (ch > 0 ? 1 : 0)) + 1)))
		return (NULL);
	res[l] = 0;
	while (l != 0)
	{
		res[--l] = (n % 10) + 48;
		n /= 10;
	}
	if (ch)
		res[0] = ch;
	return (res);
}

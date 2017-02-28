/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:48:26 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/23 17:52:26 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		i;
	int		tmp;
	char	*res;

	i = 1;
	tmp = n;
	while ((tmp /= 10) != 0)
		i++;
	tmp = 0;
	if (n < 0)
		tmp = 1;
	if (!(res = (char*)malloc((i += tmp) + 1)))
		return (NULL);
	res[i] = 0;
	while (i != 0)
	{
		if (n < 0)
			res[--i] = ((n % 10) * -1) + 48;
		else
			res[--i] = (n % 10) + 48;
		n /= 10;
	}
	if (tmp)
		res[0] = '-';
	return (res);
}

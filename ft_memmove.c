/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:05:12 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/25 15:19:27 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;
	size_t			i;

	tmp = dst;
	tmp2 = (unsigned char*)src;
	if ((tmp - tmp2) >= 0)
		while (--len != (size_t)-1)
			tmp[len] = tmp2[len];
	else
	{
		i = -1;
		while (++i < len)
			tmp[i] = tmp2[i];
	}
	return (dst);
}

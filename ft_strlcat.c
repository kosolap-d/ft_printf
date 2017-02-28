/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:35:32 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/25 20:33:54 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		sdst;
	int		ssrc;
	int		tmp;

	sdst = ft_strlen(dst);
	tmp = size - sdst;
	if (tmp <= 0)
	{
		return (ft_strlen(src) + size);
	}
	else
	{
		ft_strncat(dst, src, (size - 1 - sdst));
		return (ft_strlen(src) + sdst);
	}
}

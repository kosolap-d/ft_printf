/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:39:13 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/26 12:41:43 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t l)
{
	int		i;
	int		j;

	i = -1;
	if ((char)lit[i + 1] == 0)
		return ((char*)big);
	while ((char)big[++i])
	{
		j = 0;
		while ((char)big[i + j] == (char)lit[j] && (i + j) < (int)l)
		{
			j++;
			if ((char)lit[j] == '\0')
				return ((char*)big + i);
		}
	}
	return (NULL);
}

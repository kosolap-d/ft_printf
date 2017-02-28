/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:07:12 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/26 12:29:15 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	i = -1;
	if ((char)little[i + 1] == 0)
		return ((char*)big);
	while ((char)big[++i])
	{
		j = 0;
		while ((char)big[i + j] == (char)little[j])
		{
			j++;
			if ((char)little[j] == '\0')
				return ((char*)big + i);
		}
	}
	return (NULL);
}

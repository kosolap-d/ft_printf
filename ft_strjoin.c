/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 21:24:20 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/26 21:36:07 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(new = (char*)malloc(len_s1 + len_s2 + 1)))
		return (NULL);
	i = -1;
	while (++i < len_s1)
		new[i] = s1[i];
	len_s1 = -1;
	while (++len_s1 < len_s2)
		new[i++] = s2[len_s1];
	new[i] = '\0';
	return (new);
}

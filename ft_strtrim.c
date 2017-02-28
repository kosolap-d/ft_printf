/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 21:36:32 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/26 22:01:10 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*new;

	i = -1;
	start = 0;
	if (!s)
		return (NULL);
	while (s[++i] && s[i] < 33)
		start++;
	i = ft_strlen(s);
	end = i;
	while ((--i != -1) && ((s[i] == '\t') || (s[i] == '\v') || (s[i] == '\f')
			|| (s[i] == '\r') || (s[i] == '\n') || (s[i] == ' ')))
		end--;
	if (start == end || end == 0)
	{
		new = (char*)malloc(1);
		new[0] = '\0';
		return (new);
	}
	new = ft_strsub(s, (unsigned int)start, (size_t)(end - start));
	return (new);
}

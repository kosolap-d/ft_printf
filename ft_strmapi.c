/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:56:21 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/26 20:58:24 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	unsigned int		j;
	char				*str;

	i = 0;
	if ((!s) || (!f))
		return (NULL);
	while ((char)s[i])
		i++;
	if (!(str = (char*)malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	j = -1;
	while (++j < i)
		str[j] = f(j, (char)s[j]);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:45:24 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/26 20:54:41 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*str;

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
		str[j] = f((char)s[j]);
	return (str);
}

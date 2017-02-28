/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:18:23 by dkosolap          #+#    #+#             */
/*   Updated: 2016/12/02 14:18:37 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (s[i] == c && s[i])
		i++;
	if (i == ft_strlen(s))
		return (0);
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

static int	ft_litters(int *end, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	while (s[*end] == c)
		*end -= 1;
	j = *end;
	while (s[j] != c && j != -1)
	{
		i++;
		j--;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		count;
	int		i;
	int		end;

	if (!s || !c)
		return (NULL);
	count = ft_words(s, c);
	if (!(new = (char**)malloc((sizeof(char*) * count) + 1)))
		return (NULL);
	end = ft_strlen(s) - 1;
	while (s[end] == c && end != -1)
		end--;
	new[count] = NULL;
	while (--count != -1)
	{
		i = ft_litters(&end, s, c);
		if (!(new[count] = (char*)malloc(sizeof(char) * i + 1)))
			return (NULL);
		new[count][i] = 0;
		while (i > 0)
			new[count][--i] = s[end--];
	}
	return (new);
}

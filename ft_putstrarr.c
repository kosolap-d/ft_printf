/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:05:41 by dkosolap          #+#    #+#             */
/*   Updated: 2016/12/02 19:12:27 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstrarr(char **str, size_t len)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (i < len)
	{
		ft_putstr(str[i++]);
		ft_putchar(' ');
	}
}

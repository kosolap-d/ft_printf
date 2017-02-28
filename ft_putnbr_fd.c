/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:07:38 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/23 16:08:51 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int nb, int fb)
{
	long int	tr;
	char		c;

	tr = nb;
	if (tr < 0)
	{
		write(fb, "-", 1);
		tr *= -1;
	}
	if (tr > 9)
	{
		ft_putnbr_fd(tr / 10, fb);
	}
	c = tr % 10 + '0';
	write(fb, &c, 1);
}

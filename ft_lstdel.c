/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:15:59 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/29 16:17:00 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		if (((*alst)->next) != NULL)
			ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(alst, del);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:06:48 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/29 19:07:03 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst)
		return (NULL);
	tmp = lst;
	new = f(tmp);
	tmp2 = new;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp2->next = f(tmp);
		tmp2 = tmp2->next;
	}
	return (new);
}

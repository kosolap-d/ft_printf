/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:24:13 by dkosolap          #+#    #+#             */
/*   Updated: 2016/12/05 11:55:34 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstinsert(t_list **lst, t_list *inst, int num)
{
	int		i;
	t_list	*tmp;

	tmp = *lst;
	if (tmp == NULL)
		return (0);
	if (num == 0)
		ft_lstadd(lst, inst);
	else if (1 == num)
	{
		inst->next = tmp->next;
		tmp->next = inst;
	}
	else
		return (ft_lstinsert(&(*lst)->next, inst, num - 1));
	return (1);
}

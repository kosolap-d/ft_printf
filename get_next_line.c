/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:26:30 by dkosolap          #+#    #+#             */
/*   Updated: 2016/12/21 15:28:07 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		fu_fu(char **l, char **blc)
{
	if (((*blc) = ft_strchr((*l), '\n')))
	{
		*(*blc) = 0;
		(*blc) = ft_strdup((*blc + 1));
		return (1);
	}
	return (0);
}

int		fu_read(const int fd, char **l, char **blc)
{
	char	tmp[BUFF_SIZE + 1];
	int		res;

	ft_bzero(tmp, BUFF_SIZE + 1);
	if (fu_fu(l, blc))
		return (1);
	while ((res = read(fd, &tmp, BUFF_SIZE)) != 0 && res != -1)
	{
		*blc = *l;
		(*l) = ft_strjoin((*l), tmp);
		free(*blc);
		if (fu_fu(l, blc))
			return (1);
		ft_bzero(tmp, BUFF_SIZE + 1);
	}
	(*blc) = ft_strdup("\0");
	if (!(*l) || !(*l)[0])
		return (res);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*tlst;
	char			*tmp;
	int				res;

	if (!line)
		return (-1);
	tlst = lst;
	while (tlst && (const int)tlst->content_size != fd)
		tlst = tlst->next;
	(*line) = ft_strdup(tlst != 0 ? tlst->content : "\0");
	if ((res = fu_read((int)fd, line, &tmp)) == -1 || res == 0)
		return (res);
	if (tlst)
		tlst->content = (void *)ft_strdup(tmp == 0 ? "\0" : tmp);
	else
	{
		ft_lstadd(&lst, ft_lstnew("\0", 0));
		free(lst->content);
		lst->content = (void *)ft_strdup(tmp);
		lst->content_size = fd;
	}
	free(tmp);
	return (1);
}

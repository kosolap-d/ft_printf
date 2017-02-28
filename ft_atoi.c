/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:37:08 by dkosolap          #+#    #+#             */
/*   Updated: 2016/11/21 17:15:23 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_cos(int n)
{
	if (n > 0)
		return (-1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		arr[3];

	i = 0;
	arr[0] = 1;
	arr[2] = 0;
	arr[1] = 0;
	while ((str[i] == '\t') || (str[i] == '\v') || (str[i] == '\f')
		|| (str[i] == '\r') || (str[i] == '\n') || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			arr[0] = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		if (++arr[1] >= 20)
			return (ft_cos(arr[0]));
		arr[2] = arr[2] * 10;
		arr[2] += (str[i] - 48);
		i++;
	}
	return (arr[2] * arr[0]);
}

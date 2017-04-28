/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:22:19 by evlad             #+#    #+#             */
/*   Updated: 2017/04/28 14:41:22 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*stock_room_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[++i] == ' ')
			break ;
	}
	return (ft_strsub(str, 0, i));
}

int			stock_room_x(char *str)
{
	int		i;
	int		j;
	char	*tmp;
	int		result;

	i = 0;
	while (str[i])
	{
		if (str[++i] == ' ')
			break ;
	}
	j = i + 1;
	while (str[j])
	{
		if (str[++j] == ' ')
			break ;
	}
	tmp = ft_strsub(str, i, j - i);
	result = ft_atoi(tmp);
	free(tmp);
	return (result);
}

int			stock_room_y(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[++i] == ' ')
			break ;
	}
	j = i;
	while (str[j])
	{
		if (str[++j] == ' ')
			break ;
	}
	return (ft_atoi(str + j + 1));
}

t_room		*stock_link_1(t_all *all, char *str)
{
	char	*tmp;
	t_room	*result;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			break ;
		i++;
	}
	tmp = ft_strsub(str, 0, i);
	result = find(all, tmp);
	ft_strdel(&tmp);
	return (result);
}

t_room		*stock_link_2(t_all *all, char *str)
{
	char	*tmp;
	int		i;
	t_room	*result;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			break ;
		i++;
	}
	tmp = ft_strnew(ft_strlen(str) - i - 1);
	tmp = ft_strcpy(tmp, str + i + 1);
	result = find(all, tmp);
	ft_strdel(&tmp);
	return (result);
}

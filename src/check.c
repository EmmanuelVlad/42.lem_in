/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:40:49 by evlad             #+#    #+#             */
/*   Updated: 2017/04/27 19:02:32 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_is_room_2(char *str, int i, int j)
{
	char	*tmp;

	tmp = ft_strsub(str, i + 1, j - i - 1);
	if (!ft_strisdigit(tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	if (!ft_strisdigit(str + j + 1))
		return (0);
	return (1);
}

int		check_is_room(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (0);
		if (str[i] == ' ')
			break ;
		i++;
	}
	j = i;
	while (str[j])
	{
		if (str[++j] == ' ')
			break ;
	}
	if (str[j + 1] == '\0')
		return (0);
	return (check_is_room_2(str, i, j));
}

int		check_is_link(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (0);
		if (str[i] == '-')
			break ;
		i++;
	}
	i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int		room_exists(t_all *all, char *str, int start, int end)
{
	t_room	*room;
	char	*name;

	room = all->room;
	name = NULL;
	while (room)
	{
		name = stock_room_name(str);
		if ((ft_strcmp(room->name, name) == 0) ||
			(room->x == stock_room_x(str) && room->y == stock_room_y(str)) ||
			(room->start && start) || (room->end && end))
		{
			ft_strdel(&name);
			return (1);
		}
		ft_strdel(&name);
		room = room->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:02:37 by evlad             #+#    #+#             */
/*   Updated: 2017/04/28 15:05:35 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_start(t_all *all)
{
	t_room	*room;

	room = all->room;
	while (room)
	{
		if (room->start)
			break ;
		room = room->next;
	}
	return (room);
}

t_room		*find_end(t_all *all)
{
	t_room	*room;

	room = all->room;
	while (room)
	{
		if (room->end)
			break ;
		room = room->next;
	}
	return (room);
}

t_room		*find(t_all *all, char *str)
{
	t_room	*tmp;

	tmp = all->room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

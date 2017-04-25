/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:02:37 by evlad             #+#    #+#             */
/*   Updated: 2017/04/25 15:23:40 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_start(t_room *room)
{
	while (room->prev)
		room = room->prev;
	while (room)
	{
		if (room->start)
			return ;
		room = room->next;
	}
}

void	find_end(t_room *room)
{
	while (room->prev)
		room = room->prev;
	while (room)
	{
		if (room->end)
			return ;
		room = room->next;
	}
}

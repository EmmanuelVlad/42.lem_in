/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:43:40 by evlad             #+#    #+#             */
/*   Updated: 2017/04/25 18:35:02 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link		*init_link(char *room1, char *room2)
{
	t_link		*link;

	if (!(link = (t_link*)malloc(sizeof(t_link))))
		exit(EXIT_FAILURE);
	link->room1 = room1;
	link->room2 = room2;
	link->next = NULL;
	return (link);
}

t_room		*init_room(char *name, int start, int end, int x, int y)
{
	t_room		*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		exit(EXIT_FAILURE);
	room->name = name;
	room->start = start;
	room->end = end;
	room->x = x;
	room->y = y;
	room->occuped = 0;
	room->next = NULL;
	return (room);
}

t_all	*init_all(void)
{
	t_all	*all;

	if (!(all = (t_all*)malloc(sizeof(t_all))))
		exit(EXIT_FAILURE);
	all->ants = 0;
	all->room = NULL;
	all->link = NULL;
	all->entry = NULL;
	return (all);
}

t_entry		*init_entry(char *str, int line)
{
	t_entry		*entry;

	if (!(entry = (t_entry*)malloc(sizeof(t_entry))))
		exit(EXIT_FAILURE);
	entry->str = str;
	entry->line = line;
	entry->next = NULL;
	entry->prev = NULL;
	return (entry);
}

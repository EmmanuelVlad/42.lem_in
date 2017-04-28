/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:40:19 by evlad             #+#    #+#             */
/*   Updated: 2017/04/28 15:10:56 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_entry		*parse_line(t_all *all, t_entry *entry, int start, int end)
{
	if (check_is_room(entry->str) && !room_exists(all, entry->str, start, end))
		parse_room(all, entry, start, end);
	else if (check_is_link(entry->str) &&
			(stock_link_1(all, entry->str) != NULL &&
			 stock_link_2(all, entry->str) != NULL))
		parse_link(all, entry);
	else if (entry->str[0] == '#')
		return (entry);
	else
	{
		while (entry->next)
			entry = entry->next;
	}
	return (entry);
}

void		parse_link(t_all *all, t_entry *entry)
{
	t_room	*room1;
	t_room	*room2;
	t_link	*tmp;

	room1 = stock_link_1(all, entry->str);
	room2 = stock_link_2(all, entry->str);
	if (room1->links == NULL)
		room1->links = init_link(stock_link_2(all, entry->str));
	else
	{
		tmp = init_link(stock_link_2(all, entry->str));
		tmp->next = room1->links;
		room1->links->prev = tmp;
		room1->links = tmp;
	}
	if (room2->links == NULL)
		room2->links = init_link(stock_link_1(all, entry->str));
	else
	{
		tmp = init_link(stock_link_1(all, entry->str));
		tmp->next = room2->links;
		room2->links->prev = tmp;
		room2->links = tmp;
	}
}

void		parse_room(t_all *all, t_entry *entry, int start, int end)
{
	t_room	*tmp;
	int		startend;

	tmp = NULL;
	startend = 0;
	if (start == 1)
		startend = 1;
	else if (end == 1)
		startend = 2;
	if (all->room == NULL)
		all->room = init_room(stock_room_name(entry->str), startend,
				stock_room_x(entry->str), stock_room_y(entry->str));
	else
	{
		tmp = init_room(stock_room_name(entry->str), startend,
				stock_room_x(entry->str), stock_room_y(entry->str));
		tmp->next = all->room;
		all->room->prev = tmp;
		all->room = tmp;
	}
}

void		parse_ants(t_all *all)
{
	if (ft_strisdigit(all->entry->str))
		all->ants = ft_atoi(all->entry->str);
	else
	{
		free_all(all);
		print_exit("ERROR\n");
	}
}

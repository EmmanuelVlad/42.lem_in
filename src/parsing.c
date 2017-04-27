/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:40:19 by evlad             #+#    #+#             */
/*   Updated: 2017/04/27 19:06:42 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_entry		*parse_line(t_all *all, t_entry *entry, int start, int end)
{
	if (check_is_room(entry->str) && !room_exists(all, entry->str, start, end))
		parse_room(all, entry, start, end);
	else if (check_is_link(entry->str))
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
	t_link	*tmp;

	tmp = NULL;
	if (all->link == NULL)
		all->link = init_link(stock_link_1(entry->str),
				stock_link_2(entry->str));
	else
	{
		tmp = init_link(stock_link_1(entry->str),
				stock_link_2(entry->str));
		tmp->next = all->link;
		all->link->prev = tmp;
		all->link = tmp;
	}
	ft_printf("LINK: %s-%s\n", all->link->room1, all->link->room2);
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
	ft_printf("ROOM: %s %d - %d\n", all->room->name, all->room->x,
			all->room->y);
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

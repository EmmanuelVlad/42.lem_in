/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:40:19 by evlad             #+#    #+#             */
/*   Updated: 2017/04/25 18:12:15 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		parse_line(t_all *all, int start, int end)
{
	if (check_is_room(all->entry->str))
		parse_room(all, start, end);
	else if (check_is_link(all->entry->str))
		parse_link(all);
	else if (all->entry->str[0] == '#')
		return ;
	else
	{
		while (all->entry->next)
			all->entry = all->entry->next;
	}
}

void		parse_link(t_all *all)
{
	t_link	*tmp;

	tmp = NULL;
	if (all->link == NULL)
		all->link = init_link(stock_link_1(all->entry->str),
				stock_link_2(all->entry->str));
	else
	{
		tmp = init_link(stock_link_1(all->entry->str), 
				stock_link_2(all->entry->str));
		tmp->next = all->link;
		all->link->prev = tmp;
		all->link = tmp;
	}
	ft_printf("%s-%s\n", all->link->room1, all->link->room2);
}

void		parse_room(t_all *all, int start, int end)
{
	t_room	*tmp;

	tmp = NULL;
	if (all->room == NULL)
		all->room = init_room(stock_room_name(all->entry->str), start, end,
				stock_room_x(all->entry->str), stock_room_y(all->entry->str));
	else
	{
		tmp = init_room(stock_room_name(all->entry->str), start, end,
				stock_room_x(all->entry->str), stock_room_y(all->entry->str));
		tmp->next = all->room;
		all->room->prev = tmp;
		all->room = tmp;
	}
	ft_printf("%s: %d - %d\n", all->room->name, all->room->x, all->room->y);
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

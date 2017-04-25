/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:05:36 by evlad             #+#    #+#             */
/*   Updated: 2017/04/25 18:36:44 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_entry(t_entry *entry)
{
	t_entry		*tmp;

	tmp = NULL;
	if (entry == NULL)
		return ;
	while (entry->prev)
		entry = entry->prev;
	while (entry)
	{
		tmp = entry;
		entry = entry->next;
		free(tmp->str);
		free(tmp);
	}
	free(entry);
}

void		free_link(t_link *link)
{
	t_link		*tmp;

	tmp = NULL;
	if (link == NULL)
		return ;
	while (link->prev)
		link = link->prev;
	while (link)
	{
		tmp = link;
		link = link->next;
		free(tmp->room1);
		free(tmp->room2);
		free(tmp);
	}
	free(link);
}

void		free_room(t_room *room)
{
	t_room		*tmp;

	tmp = NULL;
	if (room == NULL)
		return ;
	while (room->prev)
		room = room->prev;
	while (room)
	{
		tmp = room;
		room = room->next;
		free(tmp->name);
		free(tmp);
	}
	free(room);
}

void	free_all(t_all *all)
{
	free_entry(all->entry);
	free_link(all->link);
	free_room(all->room);
	free(all);
}

void	print_exit(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

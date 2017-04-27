/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:05:36 by evlad             #+#    #+#             */
/*   Updated: 2017/04/27 19:07:13 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_entry(t_entry *entry)
{
	t_entry		*tmp;

	tmp = NULL;
	if (entry == NULL)
		return ;
	while (entry)
	{
		tmp = entry;
		entry = entry->next;
		if (tmp->str)
			ft_strdel(&tmp->str);
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
	while (link)
	{
		tmp = link;
		link = link->next;
		if (tmp->room1)
			ft_strdel(&tmp->room1);
		if (tmp->room2)
			ft_strdel(&tmp->room2);
		free(tmp);
	}
}

void		free_room(t_room *room)
{
	t_room		*tmp;

	tmp = NULL;
	if (room == NULL)
		return ;
	while (room != NULL)
	{
		tmp = room;
		room = room->next;
		if (tmp->name)
			ft_strdel(&tmp->name);
		if (tmp)
			free(tmp);
	}
}

void		free_all(t_all *all)
{
	free_entry(all->entry);
	free_link(all->link);
	free_room(all->room);
	free(all);
}

void		print_exit(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

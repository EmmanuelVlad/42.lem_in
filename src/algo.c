/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:25:37 by evlad             #+#    #+#             */
/*   Updated: 2017/05/18 13:56:14 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				move_to_next(t_all *all, int ant)
{
	t_room	*room;
	t_link	*tmp;

	if (find_ant(all, ant))
		room = find_ant(all, ant);
	else
		room = find_start(all);
	tmp = room->links;
	while (tmp && tmp->room->occuped)
		tmp = tmp->next;
	if (tmp == NULL)
		return (0);
	else
	{
		ft_printf("L%d-%s ", ant, tmp->room->name);
		room->occuped = 0;
		if (ft_strcmp(tmp->room->name, find_end(all)->name) == 0)
			return (1);
		tmp->room->occuped = ant;
	}
	return (0);
}

static void		add_in_queue(t_all *all, t_queue *queue, t_room *room)
{
	t_queue *tmp;

	tmp = queue;
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = init_queue(all, room);
	tmp->prev->next = tmp;
}

int				lem_in(t_all *all)
{
	t_link	*tmp;

	all->queue = init_queue(all, find_start(all));
	all->history = init_history(all, all->queue->room);
	while (all->queue)
	{
		if (all->queue->room == find_end(all))
			return (1);
		tmp = all->queue->room->links;
		while (tmp)
		{
			if (!find_history(tmp->room, all->history))
			{
				add_in_queue(all, all->queue, tmp->room);
				all->history->prev = init_history(all, tmp->room);
				all->history->prev->parent = all->queue->room;
				all->history->prev->next = all->history;
				all->history = all->history->prev;
			}
			tmp = tmp->next;
		}
		all->queue = all->queue->prev;
	}
	return (0);
}

void			lem_ino(t_all *all)
{
	int		need_to_move;
	int		i;

	need_to_move = 1;
	i = 1;
	while (need_to_move <= all->ants)
	{
		i = need_to_move;
		while (i <= all->ants)
		{
			need_to_move += move_to_next(all, i);
			i++;
		}
		write(1, "\n", 1);
	}
}

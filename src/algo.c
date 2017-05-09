/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:25:37 by evlad             #+#    #+#             */
/*   Updated: 2017/05/09 13:34:44 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		move_to_next(t_all *all, int ant)
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

void		lem_in(t_all *all)
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

int			move_to_end(t_room *room)
{
	int			moves;

	moves = 0;
	(void)room;
	return (moves);
}

t_room		*closest_to_end(t_room *room)
{
	t_room		*tmp;
	t_history	*history;

	history = init_history();
	history->room = room;
	tmp = room;
	if (tmp->start)
		tmp = tmp->links->room;
	else
		tmp = tmp->links->next->room;
	while (!tmp->end)
	{
	}
	free_history(history);
	return (room->next);
}

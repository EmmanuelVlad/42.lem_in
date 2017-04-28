/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:19:43 by evlad             #+#    #+#             */
/*   Updated: 2017/04/28 18:16:05 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void		show_all_rooms(t_all *all)
{
	t_room	*room;

	room = all->room;
	if (room == NULL)
		ft_printf("ERROR:\tNO ROOMS.\n");
	while (room)
	{
		ft_printf("ROOM `%s`\n\tX: %d\n\tY: %d\n\n", room->name, room->x,
																	room->y);
		room = room->next;
	}
}

void		show_all_links(t_room *room)
{
	t_link	*tmp;

	tmp = room->links;
	if (tmp)
		ft_printf("LINKS OF `%s`\n", room->name);
	else
		ft_printf("ERROR:\tNO LINKS FOR `%s`.\n", room->name);
	while (tmp)
	{
		ft_printf("\t`%s`\n", tmp->room->name);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

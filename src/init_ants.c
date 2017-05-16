/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 11:18:47 by evlad             #+#    #+#             */
/*   Updated: 2017/05/16 12:30:43 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_history		*init_history(void)
{
	t_history	*history;

	if (!(history = (t_history*)malloc(sizeof(t_history))))
		exit(EXIT_FAILURE);
	history->next = NULL;
	history->prev = NULL;
	return (history);
}

t_ant		*init_ant(int id)
{
	t_ant		*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		exit(EXIT_FAILURE);
	ant->id = id;
	ant->history = init_history();
	ant->next = NULL;
	ant->prev = NULL;
	return (ant);
}

t_ant		*init_ants(int total)
{
	t_ant	*tmp;
	t_ant	*ants;

	tmp = NULL;
	ants = init_ant(total--);
	while (total >= 1)
	{
		tmp = init_ant(total--);
		tmp->next = ants;
		ants->prev = tmp;
		ants = ants->prev;
	}
	return (ants);
}

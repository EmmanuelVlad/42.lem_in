/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:15:39 by evlad             #+#    #+#             */
/*   Updated: 2017/05/18 12:30:47 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_history(t_history *history)
{
	t_history	*tmp;

	tmp = NULL;
	if (!history)
		return ;
	while (history)
	{
		tmp = history;
		history = history->next;
		free(tmp);
	}
}

void		free_queue(t_queue *queue)
{
	t_queue	*tmp;

	tmp = NULL;
	if (!queue)
		return ;
	while (queue)
	{
		tmp = queue;
		queue = queue->next;
		free(tmp);
	}
}

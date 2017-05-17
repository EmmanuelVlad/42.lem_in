/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:12:12 by evlad             #+#    #+#             */
/*   Updated: 2017/05/17 10:22:03 by evlad            ###   ########.fr       */
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

void		free_ants(t_ant *ants)
{
	t_ant	*tmp;

	tmp = NULL;
	if (!ants)
		return ;
	while (ants)
	{
		tmp = ants;
		ants = ants->next;
		free_history(tmp->history);
		free(tmp);
	}
}

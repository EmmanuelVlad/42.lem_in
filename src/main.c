/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:05:40 by evlad             #+#    #+#             */
/*   Updated: 2017/04/25 18:36:39 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lem_in(t_all *all)
{
	parse_ants(all);
	all->entry = all->entry->next;
	ft_printf("%d\n", all->ants);
	while (all->entry)
	{
		if (ft_strcmp("##start", all->entry->str) == 0)
		{
			all->entry = all->entry->next;
			parse_line(all, 1, 0);
		}
		else if (ft_strcmp("##end", all->entry->str) == 0)
		{
			all->entry = all->entry->next;
			parse_line(all, 0, 1);
		}
		else
			parse_line(all, 0, 0);
		all->entry = all->entry->next;
	}
	free_all(all);
	return (0);
}

int		main(void)
{
	int			i;
	char		*line;
	t_entry		*entry;
	t_all		*all;

	i = 1;
	all = init_all();
	while (get_next_line(0, &line))
	{
		if (i == 1)
			entry = init_entry(line, i);
		else
		{
			entry->next = init_entry(line, i);
			entry->next->prev = entry;
			entry = entry->next;
		}
		i++;
	}
	ft_strdel(&line);
	while (entry->prev)
		entry = entry->prev;
	all->entry = entry;
	lem_in(all);
	return (0);
}

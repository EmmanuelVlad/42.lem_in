/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:05:40 by evlad             #+#    #+#             */
/*   Updated: 2017/05/16 10:58:44 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	process(t_all *all)
{
	t_entry	*tmp;

	parse_ants(all);
	tmp = all->entry->next;
	while (tmp)
	{
		if (ft_strcmp("##start", tmp->str) == 0)
		{
			tmp = tmp->next;
			tmp = parse_line(all, tmp, 1, 0);
		}
		else if (ft_strcmp("##end", tmp->str) == 0)
		{
			tmp = tmp->next;
			tmp = parse_line(all, tmp, 0, 1);
		}
		else
			tmp = parse_line(all, tmp, 0, 0);
		tmp = tmp->next;
	}
	show_all_rooms(all);
	show_all_links(all);
	if (!is_possible(all))
		print_free_exit("ERROR\n", all);
	else
		lem_in(all);
	free_all(all);
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
		{
			entry = init_entry(line, i);
			all->entry = entry;
		}
		else
		{
			entry->next = init_entry(line, i);
			entry->next->prev = entry;
			entry = entry->next;
		}
		i++;
	}
	ft_strdel(&line);
	process(all);
	return (0);
}

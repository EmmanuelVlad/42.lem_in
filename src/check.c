/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:40:49 by evlad             #+#    #+#             */
/*   Updated: 2017/04/25 18:25:38 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_is_room(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (0);
		if (str[i] == ' ')
			break ;
		i++;
	}
	j = i;
	while (str[j])
	{
		if (str[++j] == ' ')
			break ;
	}
	tmp = ft_strsub(str, i + 1, j - i - 1);
	if (!ft_strisdigit(tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	if (!ft_strisdigit(str + j + 1))
		return (0);
	return (1);
}

int		check_is_link(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (0);
		if (str[i] == '-')
			break ;
		i++;
	}
	i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

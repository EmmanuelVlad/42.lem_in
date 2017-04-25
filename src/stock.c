/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:22:19 by evlad             #+#    #+#             */
/*   Updated: 2017/04/25 18:25:20 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*stock_room_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[++i] == ' ')
			break ;
	}
	return (ft_strsub(str, 0, i));
}

int		stock_room_x(char *str)
{
	int		i;
	int		j;
	char	*tmp;
	int		result;

	i = 0;
	while (str[i])
	{
		if (str[++i] == ' ')
			break ;
	}
	j = i + 1;
	while (str[j])
	{
		if (str[++j] == ' ')
			break ;
	}
	tmp = ft_strsub(str, i, j - i);
	result = ft_atoi(tmp);
	free(tmp);
	return (result);
}

int		stock_room_y(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[++i] == ' ')
			break ;
	}
	j = i;
	while (str[j])
	{
		if (str[++j] == ' ')
			break ;
	}
	return (ft_atoi(str + j + 1));
}

char	*stock_link_1(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			break ;
		i++;
	}
	return (ft_strsub(str, 0, i));
}

char	*stock_link_2(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			break ;
		i++;
	}
	result = ft_strnew(ft_strlen(str) - i - 1);
	result = ft_strcpy(result, str + i + 1);
	return (result);
}

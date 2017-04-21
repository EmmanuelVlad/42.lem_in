/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:00:34 by evlad             #+#    #+#             */
/*   Updated: 2016/11/11 13:15:30 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	char *cs1;

	cs1 = s1;
	while (*s1)
		s1++;
	while (len--)
		if (!(*s1++ = *s2++))
			return (cs1);
	*s1 = '\0';
	return (cs1);
}
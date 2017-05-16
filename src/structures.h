/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:30:16 by evlad             #+#    #+#             */
/*   Updated: 2017/05/16 10:54:34 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "./lem_in.h"

/*
** --------------------------------------------------------------------------
**									STRUCTURES
** --------------------------------------------------------------------------
*/

typedef struct			s_link
{

	struct s_room		*room;
	struct s_link		*next;
	struct s_link		*prev;
}						t_link;

typedef struct			s_room
{
	char				*name;
	int					start;
	int					end;
	int					x;
	int					y;
	int					occuped;
	struct s_link		*links;
	struct s_room		*next;
	struct s_room		*prev;
}						t_room;

typedef struct			s_entry
{
	char				*str;
	int					line;
	struct s_entry		*next;
	struct s_entry		*prev;
}						t_entry;

typedef struct			s_all
{
	int					ants;
	struct s_room		*room;
	struct s_entry		*entry;
}						t_all;

typedef struct			s_history
{
	struct s_room		*room;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:06:19 by evlad             #+#    #+#             */
/*   Updated: 2017/04/25 18:36:38 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"

/*
** --------------------------------------------------------------------------
**									STRUCTURES
** --------------------------------------------------------------------------
*/

typedef struct			s_link
{
	char				*room1;
	char				*room2;
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
	struct s_link		*link;
	struct s_entry		*entry;
}						t_all;

/*
** --------------------------------------------------------------------------
**										INIT
** --------------------------------------------------------------------------
*/

t_link					*init_link(char *room1, char *room2);
t_room					*init_room(char *name, int start, int end, int x,
							int y);
t_all					*init_all(void);
t_entry					*init_entry(char *str, int line);

/*
** --------------------------------------------------------------------------
**										INIT
** --------------------------------------------------------------------------
*/

void					free_entry(t_entry *entry);
void					free_link(t_link *link);
void					free_room(t_room *room);
void					free_all(t_all *all);
void					print_exit(char *str);

/*
** --------------------------------------------------------------------------
**										FIND
** --------------------------------------------------------------------------
*/

void					find_start(t_room *room);
void					find_end(t_room *room);

/*
** --------------------------------------------------------------------------
**										PARSE
** --------------------------------------------------------------------------
*/

void					parse_line(t_all *all, int start, int end);
void					parse_ants(t_all *all);
void					parse_room(t_all *all, int start, int end);
void					parse_link(t_all *all);

/*
** --------------------------------------------------------------------------
**										CHECK
** --------------------------------------------------------------------------
*/

int						check_is_room(char *str);
int						check_is_link(char *str);

/*
** --------------------------------------------------------------------------
**										STOCK
** --------------------------------------------------------------------------
*/

char					*stock_room_name(char *str);
int						stock_room_x(char *str);
int						stock_room_y(char *str);
char					*stock_link_1(char *str);
char					*stock_link_2(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:06:19 by evlad             #+#    #+#             */
/*   Updated: 2017/05/18 12:28:03 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./structures.h"
# include "../libft/libft.h"
# include "./debug.h"

/*
** --------------------------------------------------------------------------
**										INIT
** --------------------------------------------------------------------------
*/

t_link					*init_link(t_all *all, t_room *room);
t_room					*init_room(char *name, int startend, int x, int y);
t_all					*init_all(void);
t_entry					*init_entry(t_all *all, char *str, int line);
t_history				*init_history(t_all *all, t_room *room);
t_queue					*init_queue(t_all *all, t_room *room);

/*
** --------------------------------------------------------------------------
**										FREE
** --------------------------------------------------------------------------
*/

void					free_entry(t_entry *entry);
void					free_link(t_link *link);
void					free_room(t_room *room);
void					free_all(t_all *all);
void					free_history(t_history *history);
void					free_queue(t_queue *queue);
void					free_queue_history(t_queue *queue, t_history *history);
void					print_exit(char *str);
void					print_free_exit(char *str, t_all *all);
void					free_exit(t_all *all);

/*
** --------------------------------------------------------------------------
**										FIND
** --------------------------------------------------------------------------
*/

t_room					*find_start(t_all *all);
t_room					*find_end(t_all *all);
t_room					*find_room(t_all *all, char *str);
t_room					*find_ant(t_all *all, int ant);
int						find_history(t_room *room, t_history *history);

/*
** --------------------------------------------------------------------------
**										PARSE
** --------------------------------------------------------------------------
*/

t_entry					*parse_line(t_all *all, t_entry *entry, int start,
							int end);
void					parse_ants(t_all *all);
void					parse_room(t_all *all, t_entry *entry, int start,
							int end);
void					parse_link(t_all *all, t_entry *entry);

/*
** --------------------------------------------------------------------------
**										CHECK
** --------------------------------------------------------------------------
*/

int						check_is_room(char *str);
int						check_is_link(char *str);
int						room_exists(t_all *all, char *str, int start, int end);
int						is_possible(t_all *all);

/*
** --------------------------------------------------------------------------
**										STOCK
** --------------------------------------------------------------------------
*/

char					*stock_room_name(char *str);
int						stock_room_x(char *str);
int						stock_room_y(char *str);
t_room					*stock_link_1(t_all *all, char *str);
t_room					*stock_link_2(t_all *all, char *str);

/*
** --------------------------------------------------------------------------
**										ALGO
** --------------------------------------------------------------------------
*/

int						lem_in(t_all *all);

#endif

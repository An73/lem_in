/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:07:15 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/11 15:07:17 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEM_IN_H
# define __LEM_IN_H
# include "./libft/includes/libft.h"
# include "get_next_line.h"

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				status;
	struct s_room	*next;
	struct s_way	*next_way;
}					t_room;

typedef struct		s_way
{
	char			*name_room;
	t_room			*content;
	int				content_size;
	struct s_way	*next;
}					t_way;

typedef struct		s_arr_way
{
	int					content_size;
	int					num;
	struct s_arr_way	*next;
	struct s_down		*next_down;
}					t_arr_way;

typedef struct		s_down
{
	char			*name;
	int				id_lem;
	struct s_down	*next;
	struct s_down	*back;
}					t_down;

void				n_lem(char *str, int *num, char **writer);
void				start_end_check(t_room **room_head, int st);
int					ft_atoi_lem(char *str);
void				display_error(char *str);
void				plag_room(char **room, t_room **room_head);
char				way_first(char *str);
char				start_way(char *str, t_room **head);
void				test_way(t_room **head);
void				recur(t_way *head, int line);
void				return_trip(char *str, t_room **head);
int					fin(t_room **head);
void				sort_list(t_room **head);
void				list_way(t_arr_way **head, t_way *head_fin);
void				test_arr(t_arr_way **head);
t_way				*head_way(t_room **head);
void				distribution(t_arr_way **head);
void				run(int	num_lem, t_arr_way **head);
void				check_valid_way(t_arr_way **head, t_way *start);
t_way				*st_way(t_room **head);
char				go_stop(t_arr_way **head);
char				way_check(t_arr_way **head);
void				body(t_room *room_head, int num_lem, char *writer);
char				start_and_end(t_room *room_head);
void				strjoin_lem(char **write, char *str);
char				first_b(int *num_lem, char **writer, t_room **room_head);
void				second_block(char check_way,\
	char **writer, t_room **room_head);
void				free_array(char **arr);
void				free_lst_room(t_room **head);
void				free_way(t_arr_way **head);
void				pushback(t_room **head, t_room *new);
void				list_add_start(t_down **head, t_down *new);
void				pushback_arr(t_arr_way **head, t_arr_way *new);
char				ch_way(char *str);

#endif

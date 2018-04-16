/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
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
# include <stdio.h>

typedef struct s_room
{
	char	*name;
	int		x;
	int		y;
	int		status;
	struct s_room	*next;
	struct s_way	*next_way;
}				t_room;

typedef struct		s_way
{
	char		*name_room;
	t_room			*content;
	int			content_size;
	struct s_way	*next;
}					t_way;

typedef struct  	s_arr_way
{
	int		content_size;
	int		num;
	struct s_arr_way *next;
	struct s_down *next_down;
}					t_arr_way;

typedef struct  	s_down
{
	char	*name;
	int		id_lem;
	struct 	s_down *next;
}					t_down;

void	n_lem(char *str, int *num);
void	start_end_check(t_room **room_head, int st);
int		ft_atoi_lem(char *str);
void	display_error(char *str);
void	plag_room(char **room, t_room **room_head);
char	way_first(char *str);
char	start_way(char *str, t_room **head);
void	test_way(t_room **head);
void	recur(/*t_room *room, */t_way *head, int line);
void	return_trip(char *str, t_room **head);
int	fin(t_room **head);
void	sort_list(t_room **head);


void	list_way(t_arr_way **head, t_way *head_fin);
void	test_arr(t_arr_way **head);
t_way	*head_way(t_room  **head);
/*t_arr_way	**arr_way(t_way *head_fin);
void	test_arr(t_arr_way **arrays);
t_way	*head_way(t_room  **head);*/

#endif

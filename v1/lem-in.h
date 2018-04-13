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
	t_room			*content;
	size_t			content_size;
	struct s_way	*next;
}					t_way;


void	n_lem(char *str, int *num);
void	start_end_check(t_room **room_head, int st);
int		ft_atoi_lem(char *str);
void	display_error(char *str);
void	plag_room(char **room, t_room **room_head);
char	way_first(char *str);
void	start_way(char *str, t_room **head);
void	test_way(t_room **head);

#endif

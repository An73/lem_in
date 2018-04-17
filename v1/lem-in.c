/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:05:16 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/11 16:05:17 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

void		pushback(t_room **head, t_room *new)
{
	t_room *current;

	current = *head;
	if (*head != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	else
		*head = new;
}

char	check_room(char *str)
{
	int	sp;
	int	i;

	i = 0;
	sp = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			sp++;
		i++;
	}
	if (sp == 2)
		return (1);
	return (0);
}

t_room	*new_room(char *str, int st, t_room **room_head)
{
	char	**arr_room;
	t_room	*new;
	int		i;

	i = 0;
	new = (t_room*)malloc(sizeof(t_room));
	if (check_room(str))
	{
		arr_room = ft_strsplit(str, ' ');
		while (arr_room[0][i])
			if (arr_room[0][i++] == '-')
				display_error("symbol '-' in the name of the room");
		plag_room(arr_room, room_head);
		new->name = ft_strdup(arr_room[0]);
		new->x = ft_atoi_lem(arr_room[1]);
		new->y = ft_atoi_lem(arr_room[2]);
		new->status = st;
		new->next = NULL;
		new->next_way = NULL;
	}
	else
		display_error("invalid room");
	return (new);
}

void	start_end(t_room **room_head, char *st_end)
{
	char	*str;
	//t_room	n_room;

	if (get_next_line(0, &str))
	{
		if (ft_strequ(st_end, "##start"))
		{
			start_end_check(room_head, 1);
			pushback(room_head, new_room(str, 1, room_head));
		}
		else if (ft_strequ(st_end, "##end"))
		{
			start_end_check(room_head, 2);
			pushback(room_head, new_room(str, 2, room_head));
		}
	}
}

int		main(void)
{
	char	*str;
	int		num_lem;
	char	check_way;
	t_room	*room_head;
	t_arr_way *arrays_head = NULL;

	num_lem = 0;
	while (num_lem == 0 && get_next_line(0, &str))
		n_lem(str, &num_lem);
	while (get_next_line(0, &str) && !way_first(str))
	{
		if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
			start_end(&room_head, str);
		else if (str[0] == '#')
			;
		else
			pushback(&room_head, new_room(str, 0, &room_head));
		//printf("%d\n", error_check(str, &num_lem));
	}
	check_way = start_way(str, &room_head);
	return_trip(str, &room_head);
	while (check_way && get_next_line(0, &str))
	{
		check_way = start_way(str, &room_head);
		return_trip(str, &room_head);
	}
	recur(room_head->next_way, 1);
	fin(&room_head);
	sort_list(&room_head);
	list_way(&arrays_head, head_way(&room_head));
	distribution(&arrays_head);
	check_valid_way(&arrays_head, st_way(&room_head));
	test_way(&room_head);
	test_arr(&arrays_head);
	run(num_lem, &arrays_head);
	/*while (room_head)
	{
		printf("\nname = %s\nx = %d\ny = %d\nst = %d\n\n", room_head->name, room_head->x, room_head->y, room_head->status);
		room_head = room_head->next;
	}*/
}

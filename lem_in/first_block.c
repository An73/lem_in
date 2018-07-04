/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:10:49 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/19 19:10:50 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	if (sp == 2 && str[0] != ' ' && str[0] != 'L')
		return (1);
	return (0);
}

t_room	*new_room(char *str, int st, t_room **room_head)
{
	char	**arr_room;
	t_room	*new;
	int		i;

	i = 0;
	arr_room = NULL;
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
	free_array(arr_room);
	return (new);
}

void	start_end(t_room **room_head, char *st_end, char **writer)
{
	char	*str;
	int		check;

	check = 0;
	while (check == 0 && get_next_line(0, &str))
	{
		if (str[0] == '#' && !ft_strequ(str, "##start")\
			&& !ft_strequ(str, "##end"))
			strjoin_lem(writer, str);
		else if (ft_strequ(st_end, "##start"))
		{
			start_end_check(room_head, 1);
			pushback(room_head, new_room(str, 1, room_head));
			strjoin_lem(writer, str);
			check = 1;
		}
		else if (ft_strequ(st_end, "##end"))
		{
			start_end_check(room_head, 2);
			pushback(room_head, new_room(str, 2, room_head));
			strjoin_lem(writer, str);
			check = 1;
		}
		free(str);
	}
}

void	cicle(char **str, char **writer, t_room **room_head)
{
	if (ft_strequ(*str, "##start") || ft_strequ(*str, "##end"))
	{
		strjoin_lem(writer, *str);
		start_end(room_head, *str, writer);
	}
	else if ((*str)[0] == '#')
		;
	else
		pushback(room_head, new_room(*str, 0, room_head));
	if (!way_first(*str))
	{
		if (!ft_strequ(*str, "##start") && !ft_strequ(*str, "##end"))
			strjoin_lem(writer, *str);
		free(*str);
	}
}

char	first_b(int *num_lem, char **writer, t_room **room_head)
{
	char	*str;
	char	check_way;

	while (*num_lem == 0 && get_next_line(0, &str))
		n_lem(str, num_lem, writer);
	if (*num_lem == 0)
		exit(1);
	free(str);
	while (get_next_line(0, &str) && !way_first(str))
		cicle(&str, writer, room_head);
	if (!way_first(str) || !start_and_end(*room_head))
	{
		free(str);
		display_error("no way");
	}
	check_way = start_way(str, room_head);
	if (check_way)
	{
		return_trip(str, room_head);
		strjoin_lem(writer, str);
	}
	free(str);
	return (check_way);
}

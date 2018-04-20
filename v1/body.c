/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:43:03 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/18 17:43:05 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	way_start_end(t_room *room_head)
{
	t_room *current;

	current = room_head;
	while(current)
	{
		if (current->status == 1 && current->next_way != NULL)
		{
			current = room_head;
			while (current)
			{
				if (current->status == 2 && current->next_way != NULL)
					return ;
				current = current->next;
			}
			display_error("no way");
		}
		current = current->next;
	}
	display_error("no way");
}

void	body(t_room *room_head, int num_lem, char *writer)
{
	t_arr_way *arrays_head;

	arrays_head = NULL;
	recur(st_way(&room_head), 1);
	way_start_end(room_head);
	fin(&room_head);
	sort_list(&room_head);
	list_way(&arrays_head, head_way(&room_head));
	distribution(&arrays_head);
	check_valid_way(&arrays_head, st_way(&room_head));
	if (way_check(&arrays_head))
	{
		ft_printf("%s\n\n", writer);
		run(num_lem, &arrays_head);
		free(writer);
		free_way(&arrays_head);
		//free_lst_room(&room_head);
		//system("leaks lem-in");
	}
	else
		display_error("invalid way");
}

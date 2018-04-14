/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wave.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:43:54 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/13 16:43:55 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	return_way(t_way *current)
{
	t_way	*back;

	back = current->content->next_way;
	while (back != NULL)
	{
		if (ft_strequ(current->name_room, back->content->name))
		{
			current->content_size = back->content_size;
			return ;
		}
		back = back->next;
	}
}

void	recur(/*t_room *room, */t_way *head, int line)
{
	t_way *current;

	current = head;
	while (current != NULL)
	{
		/*if (current->content_size == -1)
			return_way(current);*/
		if (current->content_size == 0 || (line < current->content_size))
		{
			/*if (current->content->status == 2)
			{
				current->content_size = line;
				return ;
			}*/
			current->content_size = line;
			recur(current->content->next_way, line + 1);
		}
		current = current->next;
	}
}

/*void	wave(t_room **head_room)
{

}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:44:29 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/13 15:44:30 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_way 	*new_way(char *end_room, t_room **head)
{
	t_room *current;
	t_way	*new;

	current = *head;
	new = (t_way*)malloc(sizeof(t_way));
	while (current != NULL)
	{
		if (ft_strequ(current->name, end_room))
		{
			new->content = current;
			new->next = NULL;
		}
		current = current->next;
	}
	return (new);

}

void	pushback_way(t_way *head_way, t_way *n_way)
{
	t_way  *current;

	current = head_way;
	while (current->next != NULL)
		current = current->next;
	current->next = n_way;
}

void	start_way(char *str, t_room **head)
{
	char  **room_way;
	t_room	*current;
	t_way 	*n_way;

	current = *head;
	room_way = ft_strsplit(str, '-');
	n_way = new_way(room_way[1], head);
	while (current != NULL)
	{
		if (ft_strequ(current->name, room_way[0]))
		{
			if (current->next_way == NULL)
				current->next_way = n_way;
			else
				pushback_way(current->next_way, n_way);
		}
		current = current->next;
	}
}

void	test_way(t_room **head)
{
	t_room *current;
	t_way *cur_way;

	current = *head;
	while (current != NULL)
	{
		if (current->next_way != NULL)
		{
			cur_way = current->next_way;
			while (cur_way != NULL)
			{
				printf("start %s -----> end %s\n", current->name,  cur_way->content->name);
				cur_way = cur_way->next;
			}
		}
		current = current->next;
	}
}
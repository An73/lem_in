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

#include "lem_in.h"

t_way	*new_way(char *end_room, t_room **head)
{
	t_room	*current;
	t_way	*new;
	char	check;

	current = *head;
	check = 0;
	new = (t_way*)malloc(sizeof(t_way));
	while (current != NULL)
	{
		if (ft_strequ(current->name, end_room))
		{
			new->content = current;
			new->content_size = 0;
			new->next = NULL;
			check = 1;
		}
		current = current->next;
	}
	if (check == 0)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

void	pushback_way(t_way *head_way, t_way *n_way)
{
	t_way	*current;

	current = head_way;
	while (current->next != NULL)
		current = current->next;
	current->next = n_way;
}

char	start_way(char *str, t_room **head)
{
	char	**room_way;
	t_room	*current;
	t_way	*n_way;

	current = *head;
	room_way = ft_strsplit(str, '-');
	n_way = new_way(room_way[1], head);
	while (current != NULL && n_way != NULL)
	{
		if (ft_strequ(current->name, room_way[0]))
		{
			n_way->name_room = ft_strdup(current->name);
			if (current->next_way == NULL)
				current->next_way = n_way;
			else
				pushback_way(current->next_way, n_way);
			free_array(room_way);
			return (1);
		}
		current = current->next;
	}
	free(n_way);
	free_array(room_way);
	return (0);
}

void	return_trip(char *str, t_room **head)
{
	char	**room_way;
	t_room	*current;
	t_way	*n_way;

	current = *head;
	room_way = ft_strsplit(str, '-');
	n_way = new_way(room_way[0], head);
	while (current != NULL)
	{
		if (ft_strequ(current->name, room_way[1]))
		{
			n_way->name_room = ft_strdup(current->name);
			if (current->next_way == NULL)
				current->next_way = n_way;
			else
				pushback_way(current->next_way, n_way);
			free_array(room_way);
			return ;
		}
		current = current->next;
	}
	free(n_way);
	free_array(room_way);
}

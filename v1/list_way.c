/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:14:01 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/15 16:14:02 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		check_check(t_arr_way **head, char *name)
{
	t_arr_way	*current;
	t_down		*down;

	current = *head;
	while (current)
	{
		down = current->next_down;
		while (down)
		{
			if (ft_strequ(down->name, name))
				return (0);
			down = down->next;
		}
		current = current->next;
	}
	return (1);
}

t_down		*elem_way(t_way *way)
{
	t_down	*new;

	new = (t_down*)malloc(sizeof(t_down));
	new->name = ft_strdup(way->name_room);
	new->id_lem = 0;
	new->next = NULL;
	new->back = NULL;
	return (new);
}

t_down		*rave_way(t_way *way, t_arr_way **head)
{
	t_way	*current;
	t_down	*head_down;
	int		num;

	num = -1;
	current = way;
	head_down = NULL;
	while (current)
	{
		if (num == -1 || (check_check(head, current->content->name)\
			&& current->content->next_way->content_size < num))
		{
			list_add_start(&head_down, elem_way(current));
			current = current->content->next_way;
			num = current->content_size;
		}
		else
			current = current->next;
	}
	return (head_down);
}

t_arr_way	*new_up(t_way *fin)
{
	t_arr_way	*new;

	new = (t_arr_way*)malloc(sizeof(t_arr_way));
	new->content_size = fin->content_size;
	new->num = 0;
	new->next = NULL;
	new->next_down = NULL;
	return (new);
}

void		list_way(t_arr_way **head, t_way *head_fin)
{
	t_arr_way	*arr;
	t_way		*way_current;

	way_current = head_fin;
	while (way_current)
	{
		pushback_arr(head, new_up(way_current));
		way_current = way_current->next;
	}
	arr = *head;
	while (head_fin)
	{
		arr->next_down = rave_way(head_fin, head);
		arr = arr->next;
		head_fin = head_fin->next;
	}
}

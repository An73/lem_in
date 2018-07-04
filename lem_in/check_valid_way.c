/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_way.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:37:36 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/17 15:37:37 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	num_fin(t_arr_way **head, t_way *fin)
{
	t_arr_way	*current;

	current = *head;
	while (current)
	{
		if (ft_strequ(current->next_down->name, fin->name_room))
			current->num = 0;
		current = current->next;
	}
}

t_way	*st_way(t_room **head)
{
	t_room	*current;

	current = *head;
	while (current->status != 1)
		current = current->next;
	return (current->next_way);
}

void	check_valid_way(t_arr_way **head, t_way *start)
{
	t_arr_way	*current;
	t_way		*st_cur;
	int			check;

	current = *head;
	while (current)
	{
		st_cur = start;
		check = 0;
		while (st_cur && check == 0)
		{
			if (ft_strequ(current->next_down->name, st_cur->content->name))
				check = 1;
			st_cur = st_cur->next;
		}
		if (check == 0)
			current->num = -1;
		current = current->next;
	}
}

char	go_stop(t_arr_way **head)
{
	t_arr_way	*current;
	t_down		*down;

	current = *head;
	while (current)
	{
		down = current->next_down;
		while (down)
		{
			if (down->id_lem != 0)
				return (1);
			down = down->next;
		}
		current = current->next;
	}
	return (0);
}

char	way_check(t_arr_way **head)
{
	t_arr_way *current;

	current = *head;
	while (current)
	{
		if (current->num != -1)
			return (1);
		current = current->next;
	}
	return (0);
}

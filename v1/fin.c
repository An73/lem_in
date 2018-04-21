/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:50:41 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/15 12:50:42 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		fin(t_room **head)
{
	t_room	*current;
	t_way	*way_cur;

	current = *head;
	while (current)
	{
		if (current->status == 2)
		{
			way_cur = current->next_way;
			while (way_cur)
			{
				way_cur->content_size =\
				way_cur->content->next_way->content_size;
				way_cur = way_cur->next;
			}
			return (1);
		}
		current = current->next;
	}
	return (0);
}

void	swap_way(t_way **current)
{
	int		temp;
	t_room	*content_temp;

	temp = (*current)->content_size;
	content_temp = (*current)->content;
	(*current)->content_size = (*current)->next->content_size;
	(*current)->content = (*current)->next->content;
	(*current)->next->content_size = temp;
	(*current)->next->content = content_temp;
}

void	sort(t_way *head)
{
	t_way	*current;
	t_way	*last;
	char	q;

	last = NULL;
	q = 1;
	while (q && head != NULL)
	{
		q = 0;
		current = head;
		while (current->next != last)
		{
			if (current->content_size > current->next->content_size)
			{
				swap_way(&current);
				q = 1;
			}
			current = current->next;
		}
		last = current;
	}
}

void	sort_list(t_room **head)
{
	t_room	*current;

	current = *head;
	while (current)
	{
		sort(current->next_way);
		current = current->next;
	}
}

t_way	*head_way(t_room **head)
{
	t_room	*current;

	current = *head;
	while (current->status != 2)
		current = current->next;
	return (current->next_way);
}

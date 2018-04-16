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

#include "lem-in.h"

char	check_check(t_arr_way **head, char *name)
{
	t_arr_way *current;
	t_down *down;

	current = *head;
	while (current)
	{
		down = current->next_down;
		while (down)
		{
			write(1, "2", 1);
			if (ft_strequ(down->name, name))
				return (0);
			down = down->next;
		}
		current = current->next;
	}
	return (1);
}

t_down *elem_way(t_way *way)
{
	t_down *new;

	new = (t_down*)malloc(sizeof(t_down));
	new->name = ft_strdup(way->name_room);
	new->next = NULL;
	return (new);
}

void		pushback_down(t_down **head, t_down *new)
{
	t_down *current;

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

void	list_add_start(t_down **head, t_down *new)
{
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		new->next = *head;
		*head = new;
	}
}

t_down	*rave_way(t_way *way, t_arr_way **head)
{
	t_way *current;
	t_down *head_down;
	int		num;

	num = -1;
	current = way;
	head_down = NULL;
	while (current && current->content_size != 1)
	{
		printf("name _room = %s\n", current->name_room);
		write(1, "+", 1);
		//printf("%s --> %s\n", current->name_room, current->content->name);
		if (num == -1 || (check_check(head, current->content->name) && current->content->next_way->content_size < num))
		{
			write(1, "=", 1);
			//pushback_down(&head_down, elem_way(current));
			list_add_start(&head_down, elem_way(current));
			printf("[%s IF ]\n", head_down->name);
			current = current->content->next_way;
			num = current->content_size;
		}
		else
		{
			current = current->next;
		}
	}

	return (head_down);
}

t_arr_way	*new_up(t_way *fin)
{
	t_arr_way *new;

	new = (t_arr_way*)malloc(sizeof(t_arr_way));
	new->content_size = fin->content_size;
	new->num = 0;
	new->next = NULL;
	new->next_down = NULL;
	return (new);
}

void		pushback_arr(t_arr_way **head, t_arr_way *new)
{
	t_arr_way *current;

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

void	list_way(t_arr_way **head, t_way *head_fin)
{
	t_arr_way *arr;
	//int		cost;
	t_way *way_current;

	way_current  = head_fin;
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

void	test_arr(t_arr_way **head)
{
	t_arr_way *current;
	t_down *cur_down;

	current = *head;
	while (current != NULL)
	{
		cur_down = current->next_down;
		while (cur_down != NULL)
		{
			printf("['%s']->", cur_down->name);
			cur_down = cur_down->next;
		}
		printf("\n");
		current = current->next;
	}
}
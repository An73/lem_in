/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:00:08 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/21 15:00:10 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		pushback(t_room **head, t_room *new)
{
	t_room	*current;

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

void		list_add_start(t_down **head, t_down *new)
{
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = *head;
		(*head)->back = new;
		*head = new;
	}
}

void		pushback_arr(t_arr_way **head, t_arr_way *new)
{
	t_arr_way	*current;

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

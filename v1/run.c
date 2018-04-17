/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:49:36 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/16 16:49:38 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	distribution(t_arr_way **head)
{
	t_arr_way *current;
	int		pass;

	current = *head;
	pass = 0;
	while (current && pass == 0)
	{
		if (current->num != -1)
		{
			current->num = pass;
			pass = current->content_size;
		}
		current = current->next;
	}
	while (current)
	{
		if (current->num != -1)
		{
			pass += current->content_size;
			current->num = pass;
		}
		current = current->next;
	}
}

void	printer(t_down *head)
{
	t_down *current;

	current = head;
	while (current)
	{
		if (current->id_lem != 0 && current->next != NULL)
			ft_printf("L%d-%s ", current->id_lem, current->name);
		/*else if (current->id_lem != 0)
			ft_printf("L%d-%s", current->id_lem, current->name);*/
		current = current->next;
	}
}

void	rider(int id, t_down *head)
{
	t_down *current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	while (current->back != NULL)
	{
		current->id_lem = current->back->id_lem;
		current = current->back;
	}
	current->id_lem = id;
	printer(head);
}

void	run(int	num_lem, t_arr_way **head)
{
	int		id;
	t_arr_way *current;

	id = 1;
	while (id == 1 || go_stop(head))
	{
		current = *head;
		while (current)
		{
			if (current->num != -1 && (num_lem - id) >= current->num)
			{
				rider(id, current->next_down);
				id++;
			}
			else if (current->num != -1)
				rider(0, current->next_down);
			current = current->next;
		}
		ft_printf("\n");
	}
}

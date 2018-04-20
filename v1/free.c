/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:04:49 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/19 21:04:50 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	free_array(char **arr)
{
	int		i;

	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_lst(t_way *head)
{
	t_way *current;
	t_way	*buff;

	current = head;
	while (current != NULL)
	{
		buff = current->next;
		free(current->name_room);
		free(current);
		current = buff;
	}
	head = NULL;
}

void	free_lst_room(t_room **head)
{
	t_room *current;
	t_room	*buff;

	current = *head;
	while (current != NULL)
	{
		buff = current->next;
		free_lst(current->next_way);
		free(current->name);
		free(current);
		current = buff;
	}
	*head = NULL;
}

void	free_down(t_down *head)
{
	t_down *current;
	t_down	*buff;

	current = head;
	while (current != NULL)
	{
		buff = current->next;
		free(current->name);
		free(current);
		current = buff;
	}
	head = NULL;
}

void	free_way(t_arr_way **head)
{
	t_arr_way *current;
	t_arr_way	*buff;

	current = *head;
	while (current != NULL)
	{
		buff = current->next;
		free_down(current->next_down);
		free(current);
		current = buff;
	}
	*head = NULL;
}

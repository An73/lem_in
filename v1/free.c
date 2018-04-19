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
}

void	free_lst(t_room **head)
{
	t_room *current;
	t_room	*buff;

	current = *head;
	while (current != NULL)
	{
		buff = current->next;
		free(current->name);
		free(current);
		current = buff;
	}
	*head = NULL;
}


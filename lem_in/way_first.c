/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:16:42 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/21 15:16:43 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	start_and_end(t_room *room_head)
{
	t_room	*current;

	current = room_head;
	while (current)
	{
		if (current->status == 1)
		{
			current = room_head;
			while (current)
			{
				if (current->status == 2)
					return (1);
				current = current->next;
			}
			return (0);
		}
		current = current->next;
	}
	return (0);
}

char	way_first(char *str)
{
	char	**arr;
	int		i;

	if (!ft_strchr(str, ' ') && str[0] != '#')
	{
		arr = ft_strsplit(str, '-');
		i = 0;
		while (arr[i])
			i++;
		if (i == 2)
		{
			free_array(arr);
			return (1);
		}
		free_array(arr);
		return (0);
	}
	return (0);
}

char	ch_way(char *str)
{
	int		i;
	int		def;

	i = 0;
	def = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			def++;
		i++;
	}
	if (def == 1)
		return (1);
	return (0);
}

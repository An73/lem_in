/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:49:24 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/11 14:49:30 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

int		str_to_num(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			display_error("invalid number");
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

void	n_lem(char *str, int *num)
{
	if ((ft_strequ(str, "##start") || ft_strequ(str, "##end")) && *num == 0)
		display_error("no amount of ants");
	if (*num == 0 && str[0] != '#')
	{
		*num = str_to_num(str);
		if (*num <= 0)
			display_error("invalid number");
	}
}

void	start_end_check(t_room **room_head, int st)
{
	t_room	*current;

	current = *room_head;
	while (current)
	{
		if (current->status == st)
			display_error("second ##start or ##end");
		current = current->next;
	}
}

void	display_error(char *str)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	plag_room(char **room, t_room **room_head)
{
	t_room *current;

	current = *room_head;
	while (current != NULL)
	{
		if (ft_strequ(current->name, room[0]))
			display_error("room name reserved");
		else if (current->x == ft_atoi_lem(room[1]) && current->y == ft_atoi_lem(room[2]))
			display_error("coordinates are reserved");
		current = current->next;
	}
}

char	way_first(char *str)
{
	if (ft_strlen(str) == 3 && str[1] == '-')
		return (1);
	return (0);
}
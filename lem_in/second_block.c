/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:18:00 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/19 19:18:02 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	second_block(char check_way, char **writer, t_room **room_head)
{
	char	*str;

	while (check_way && get_next_line(0, &str))
	{
		if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
		{
			free(str);
			display_error("second ##start or ##end");
		}
		else if (str[0] == '#')
			strjoin_lem(writer, str);
		else
		{
			check_way = start_way(str, room_head);
			if (check_way)
			{
				return_trip(str, room_head);
				strjoin_lem(writer, str);
			}
		}
		free(str);
	}
	if (check_way)
		free(str);
}

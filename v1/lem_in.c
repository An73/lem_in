/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:05:16 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/11 16:05:17 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	char	*writer;
	int		num_lem;
	char	check_way;
	t_room	*room_head;

	num_lem = 0;
	writer = NULL;
	room_head = NULL;
	check_way = first_b(&num_lem, &writer, &room_head);
	second_block(check_way, &writer, &room_head);
	body(room_head, num_lem, writer);
	free_lst_room(&room_head);
}

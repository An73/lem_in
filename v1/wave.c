/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wave.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:43:54 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/13 16:43:55 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	return_way(t_way *current)
{
	t_way	*back;

	back = current->content->next_way;
	while (back != NULL)
	{
		if (ft_strequ(current->name_room, back->content->name))
		{
			current->content_size = back->content_size;
			return ;
		}
		back = back->next;
	}
}

void	recur(/*t_room *room, */t_way *head, int line)
{
	t_way *current;

	current = head;
	while (current != NULL)
	{
		/*if (current->content_size == -1)
			return_way(current);*/
		if (current->content_size == 0 || (line < current->content_size))
		{
			/*if (current->content->status == 2)
			{
				current->content_size = line;
				return ;
			}*/
			current->content_size = line;
			recur(current->content->next_way, line + 1);
		}
		current = current->next;
	}
}

/*char	check_check(t_arr_way **arrays, char *name)
{
	int		i;
	int		k;

	i = 0;
	while (arrays[i])
	{
		k = 0;
		while (arrays[i][k].content_size)
		{
			if (ft_strequ(arrays[i][k].name, name))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

t_arr_way 	*qwert(t_way *head, t_arr_way **arrays)
{
	t_arr_way *array_way;
	t_way *current;
	int		i;
	int		cost;

	cost = head->content_size;
	array_way = (t_arr_way*)malloc(sizeof(t_arr_way) * head->content_size);
	array_way[0].name = ft_strdup(head->name_room);
	array_way[0].content_size = -1;
	i = 1;
	current = head->content->next_way;
	while (current)
	{
		write(1, "+", 1);
		if (check_check(arrays, current->name_room) && (current->content_size < array_way[i - 1].content_size
		 || array_way[i - 1].content_size == -1))
		{
			write(1, "-", 1);
			array_way[i].name = ft_strdup(current->name_room);
			array_way[i].content_size = cost;
			current = current->content->next_way;
			i++;
		}
		else
			current = current->next;
	}
	array_way[i].content_size = 0;
	return (array_way);
}

int		count_head(t_way *head_fin)
{
	int		c;
	t_way 	*current;

	c = 0;
	current = head_fin;
	while (current)
	{
		current = current->next;
		c++;
	}
	return (c + 1);
}

t_arr_way	**arr_way(t_way *head_fin)
{
	t_arr_way **arrays;
	t_way 	*current;
	int		num_fin;
	int		i;

	current = head_fin;
	num_fin = count_head(head_fin);
	arrays = (t_arr_way**)malloc(sizeof(t_arr_way*) * num_fin);
	i = 0;
	while (current)
	{
		arrays[i++] = qwert(current, arrays);
		current = current->next;
	}
	arrays[i] = NULL;
	return (arrays);
}

void	test_arr(t_arr_way **arrays)
{
	int		i;
	int		k;

	i = 0;
	while(arrays[i])
	{
		k = 0;
		while (arrays[i][k].content_size)
		{
			printf("['%s'  sort = %d] ->", arrays[i][k].name, arrays[i][k].content_size);
			k++;
		}
		printf("\n");
		i++;
	}
}*/

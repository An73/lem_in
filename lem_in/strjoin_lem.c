/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_lem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:20:35 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/19 16:20:37 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	strjoin_lem(char **write, char *str)
{
	char	*tmp;

	tmp = *write;
	*write = ft_strjoin(*write, "\n");
	free(tmp);
	tmp = *write;
	*write = ft_strjoin(*write, str);
	free(tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 21:40:54 by dkotenko          #+#    #+#             */
/*   Updated: 2018/04/11 21:40:55 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_atoi_lem(char *str)
{
	int		sum;
	int		neg;
	int		i;

	sum = 0;
	i = 0;
	neg = 1;
	while (str[i] == '\v' || str[i] == '\r' || str[i] == '\f' ||\
			str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-' && str[i + 1])
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		display_error("invalid coordinates");
	return (sum * neg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:05:21 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/12 17:04:27 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	char	*str;

	str = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:13:32 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/20 11:35:55 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_c(char const *str, char c)
{
	int			count;

	count = 0;
	while (*str == c && *str != '\0')
		str++;
	while (*str != c && *str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

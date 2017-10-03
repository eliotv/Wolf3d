/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:13:13 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/20 10:10:42 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	if (!*little)
		return ((char*)big);
	while (big[i] && i < n)
	{
		len = 0;
		j = 0;
		while (big[i] == little[j] && big[i] && i < n)
		{
			i++;
			j++;
			len++;
			if (!little[j])
				return ((char*)big + i - len);
		}
		i = i - len;
		i++;
	}
	return (0);
}

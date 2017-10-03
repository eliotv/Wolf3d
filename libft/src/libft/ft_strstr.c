/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:57:47 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/19 12:51:41 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *str1;
	char *str2;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		if (*big == *little)
		{
			str1 = (char *)big + 1;
			str2 = (char *)little + 1;
			while (*str1 && *str2 && *str1 == *str2)
			{
				str1++;
				str2++;
			}
			if (!*str2)
				return ((char*)big);
		}
		big++;
	}
	return (0);
}

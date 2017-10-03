/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:20:52 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/05 17:14:49 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && n > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}

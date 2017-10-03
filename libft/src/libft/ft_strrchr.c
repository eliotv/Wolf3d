/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:52:30 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/19 13:41:37 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen((char*)s);
	while (i <= len && s[len] != (char)c)
		len--;
	if (s[len] == (char)c)
		return ((char*)&s[len]);
	return (0);
}

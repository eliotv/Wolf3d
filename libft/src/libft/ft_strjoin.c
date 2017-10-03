/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:42:42 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 15:47:45 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		len2;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (0);
	ft_strncpy(str, (char*)s1, len);
	ft_strcat(str, s2);
	return (str);
}

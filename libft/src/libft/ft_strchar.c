/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:44:17 by evanheum          #+#    #+#             */
/*   Updated: 2017/05/02 14:44:18 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchar(const char *s, int c, int b)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == (char)c) || (s[i] == (char)b))
			return (ft_strsub(s, 0, i));
		i++;
	}
	if ((s[i] == (char)c) || (s[i] == (char)b))
		return (ft_strsub(s, 0, i));
	return (NULL);
}

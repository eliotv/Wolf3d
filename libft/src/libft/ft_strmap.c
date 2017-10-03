/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:08:59 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/19 13:19:28 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;
	int		len;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	new = ft_memalloc(len + 1);
	if (!new)
		return (0);
	while (*s != '\0')
	{
		new[i++] = f(*s++);
	}
	return (new);
}

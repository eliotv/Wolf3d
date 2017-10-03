/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:39:59 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/19 13:15:38 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;
	int				len;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	new = ft_memalloc(len + 1);
	if (!new)
		return (0);
	while (*s != '\0')
	{
		new[i] = f(i, *s++);
		i++;
	}
	return (new);
}

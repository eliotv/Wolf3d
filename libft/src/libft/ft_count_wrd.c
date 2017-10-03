/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_wrd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 10:54:13 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/21 18:53:30 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_wrd(char const *swrd, char c)
{
	int			count;
	const char	*s;

	s = swrd;
	count = 0;
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

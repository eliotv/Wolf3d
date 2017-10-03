/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa_bs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:46:32 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 15:46:49 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_u_itoa_bs(uintmax_t value, int base)
{
	uintmax_t	n;
	int			len;
	char		*str;

	len = ft_count_unint_len(value, base);
	n = value;
	if (n == 0)
		return (ft_strdup("0"));
	str = (char*)ft_memalloc(len + 1);
	if (!str)
		return (0);
	len--;
	str[len] = '\0';
	while (n > 0)
	{
		if (n % base <= 9)
			str[--len] = (n % base) + '0';
		else
			str[--len] = (n % base) + 87;
		n = n / base;
	}
	return (str);
}

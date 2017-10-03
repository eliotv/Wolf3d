/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:02:38 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 15:39:09 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(intmax_t n)
{
	char		*str;
	uintmax_t	num;
	size_t		len;
	int			neg;

	neg = (n >= 0) ? 0 : 1;
	len = ft_count_int_len(n, 10);
	if (neg == 1)
		num = n * -1;
	else
		num = n;
	if (num == 0)
		return (ft_strdup("0"));
	str = (char*)malloc(len);
	if (!str)
		return (0);
	len--;
	str[len] = '\0';
	(neg == 1) ? str[0] = '-' : 0;
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}

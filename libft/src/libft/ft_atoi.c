/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:25:29 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/20 17:42:46 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	answer;
	int					pos_neg;
	int					n;

	answer = 0;
	pos_neg = 1;
	n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		pos_neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		answer = answer * 10 + (*str++ - '0');
		n++;
	}
	if (n > 19)
		return ((pos_neg == 1) ? -1 : 0);
	return (answer * pos_neg);
}

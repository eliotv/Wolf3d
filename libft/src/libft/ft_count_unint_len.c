/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_unint_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:36:50 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 15:36:58 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_unint_len(uintmax_t n, int base)
{
	size_t	i;

	i = 2;
	if (n == 0)
	{
		n = 0;
		return (i);
	}
	while (n /= base)
		i++;
	return (i);
}

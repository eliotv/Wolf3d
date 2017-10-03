/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:37:24 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 15:37:41 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putstrn(char *str, intmax_t len)
{
	intmax_t	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] <= len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

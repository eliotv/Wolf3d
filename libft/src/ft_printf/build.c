/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:23 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 15:26:32 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_plchdr		*init_res(t_plchdr *res)
{
	if (res)
		free(res);
	res = NULL;
	res = (t_plchdr*)malloc(sizeof(t_plchdr));
	res->len = 0;
	res->width = 0;
	res->plus = 0;
	res->k = ' ';
	res->p = 0;
	res->p_width = 0;
	res->hash = 0;
	res->minus = 0;
	res->size = 0;
	res->neg = 0;
	res->base = 0;
	res->sf = 0;
	res->null = 0;
	res->z = 0;
	return (res);
}

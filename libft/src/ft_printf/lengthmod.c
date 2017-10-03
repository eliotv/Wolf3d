/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengthmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:28 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 15:27:46 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	h_mod(char **format, t_plchdr *res)
{
	if (**format == 'h' && res->len < 2)
	{
		res->len = 2;
		(*format)++;
		if (*(*format) == 'h')
		{
			res->len = 1;
			(*format)++;
		}
	}
}

void	ll_mod(char **format, t_plchdr *res)
{
	if (res->len < 3 && **format == 'l')
	{
		res->len = 3;
		(*format)++;
		if (*(*format) == 'l')
		{
			res->len = 4;
			(*format)++;
		}
	}
}

char	length_mod_ck(char **format, t_plchdr *res)
{
	if (L_MOD)
	{
		h_mod(format, res);
		ll_mod(format, res);
		if (res->len < 5 && **format == 'z')
		{
			res->len = 5;
			(*format)++;
		}
		if (res->len < 6 && **format == 'j')
		{
			res->len = 6;
			(*format)++;
		}
		else
			(L_MOD) ? (*format)++ : 0;
	}
	return (**format);
}

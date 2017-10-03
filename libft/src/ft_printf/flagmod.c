/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:15 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 15:29:51 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	hash_handler(char **format, t_plchdr *res)
{
	if (((**format == 'o' || **format == 'O') && res->p == 1) ||
	((**format == 'o' || **format == 'O') && res->hash == 1))
	{
		{
			if (res->width == 0 && res->size != res->p_width)
				res->size++;
			ft_putchar('0');
			(res->p_width > 1) ? res->p_width-- : 0;
			(res->p_width == 1) ? res->size++ : 0;
		}
	}
	if ((**format == 'x' && res->p == 1) || (**format == 'x' && res->hash == 1))
	{
		(res->width == 0) ? res->size += 2 : 0;
		ft_putstr("0x");
	}
	if ((**format == 'X' && res->p == 1) || (**format == 'X' && res->hash == 1))
	{
		(res->width == 0) ? res->size += 2 : 0;
		ft_putstr("0X");
	}
	((**format == 'x' || **format == 'X' || **format == 'o') && res->minus == 1)
		? res->width-- : 0;
	((**format == 'x' || **format == 'X') && res->minus == 1)
		? res->width-- : 0;
}

char	**minus_flag(char **format, t_plchdr *res)
{
	res->minus = 1;
	(*format)++;
	if (**format == '+')
	{
		res->plus = 1;
		(*format)++;
	}
	return (format);
}

char	**plus_flag(char **format, t_plchdr *res)
{
	res->plus = 1;
	(*format)++;
	if (**format == '+')
		(*format)++;
	if (**format == '-')
	{
		res->minus = 1;
		(*format)++;
	}
	return (format);
}

char	**zero_flag(char **format, t_plchdr *res)
{
	if (**format == '0' && res->minus == 0)
	{
		res->k = '0';
		(*format)++;
		res->z = 1;
	}
	else if (**format == '0')
		(*format)++;
	return (format);
}

void	space_flag(char **format, char *s, t_plchdr *res)
{
	if (res->minus == 0 && *s != '-' && res->sf == 1 && (**format == 'd' ||
		**format == 'i') && res->plus == 0)
	{
		res->size++;
		ft_putchar(' ');
	}
}

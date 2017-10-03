/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widthmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:35 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/08 15:30:41 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	width_mod(char **format, va_list ap, t_plchdr *res)
{
	res->width = va_arg(ap, intmax_t);
	(*format)++;
}

void	put_width_spc(char **format, char *s, t_plchdr *res)
{
	intmax_t n;

	n = ft_strlen(s);
	if ((n == 0 && s == 0) || (**format == 'c' && *s == 0))
		n = 1;
	if (n == 0)
		res->p_width = 0;
	if (res->p == 1)
		n = percision_mod(format, res, s, n);
	if (n < res->width && res->minus == 1)
		neg_flg_width(format, res, s, n);
	else if (n < res->width && res->plus == 1)
		pos_flg_width(format, res, s, n);
	else if (n < res->width)
		width_flg(format, res, s, n);
	else
		print_edge(format, res, s, n);
}

char	**get_width_len(char **format, t_plchdr *res)
{
	res->width = ft_atoi(*format);
	res->size += res->width;
	while (NUM_MOD || **format == '.' || **format == '*')
	{
		if (**format == '.')
		{
			res->p = 1;
			(*format)++;
			res->p_width = ft_atoi(*format);
		}
		else
			(*format)++;
	}
	if (**format != 's')
		res->p = 0;
	return (format);
}

char	**perc_width(char **format, t_plchdr *res)
{
	res->p_width = ft_atoi(*format);
	while (!F_SPEC)
		(*format)++;
	if (F_T != 's' && F_T != 'd' && F_T != 'o' && F_T != 'x' && F_T != 'u' &&
		F_T != 'U' && F_T != 'i' && F_T != 'p' && F_T != 'O' && F_T != 'X')
		res->p = 0;
	return (format);
}

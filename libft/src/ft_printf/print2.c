/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:13:23 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 15:58:31 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	width_flg(char **format, t_plchdr *res, char *s, int n)
{
	intmax_t k;

	k = 0;
	(res->hash == 1 && res->p == 0 && **format != 's' && (**format != 'd' ||
		**format != 'i') && **format != 'o') ? res->width-- : 0;
	(res->hash == 1 && ((**format == 'o') || (**format == 'x') ||
		(**format == 'X'))) ? res->width-- : 0;
	(res->plus == 1 && res->hash == 0) ? ft_putchar('+') : 0;
	if (*s == '-' && res->k == '0')
	{
		ft_putchar(*s);
		s++;
	}
	(res->k == '0') ? hash_handler(format, res) : 0;
	if (n < res->p_width)
	{
		res->k = ' ';
		(*s == '-') ? res->p_width++ : 0;
		k = (res->p_width > (intmax_t)ft_strlen(s) && **format == 's') ?
			ft_strlen(s) : res->p_width;
		while (k < res->width--)
			ft_putstr(&res->k);
	}
	width_flg_2(format, res, s, n);
}

void	width_flg_2(char **format, t_plchdr *res, char *s, int n)
{
	while (n < res->width)
	{
		if (res->sf == 1)
		{
			ft_putchar(' ');
			res->width--;
		}
		if (res->width-- >= res->p_width)
		{
			(res->p_width != 0 && res->neg == 1) ? res->k = ' ' : 0;
			ft_putstr(&res->k);
		}
		res->k = res->k == '0' && res->p_width != 0 ? ' ' : res->k;
	}
	if (DIG_MOD)
		width_num(format, res, &s, n);
	(res->k == ' ') ? hash_handler(format, res) : 0;
	if (res->p == 1)
		put_perc(format, s, res);
	else if (res->p_width == -1 && *s == '0' && res->hash == 0 && res->sf == 0)
		ft_putchar(' ');
	else if (*s == 0)
		write(1, s, n);
	else
		ft_putstr(s);
}

char	*width_num(char **format, t_plchdr *res, char **s, int n)
{
	((res->p_width > res->width) && (F_T != 'd' && F_T != 'D' && F_T != 'o' &&
		F_T != 'O' && F_T != 'x' && F_T != 'X' && F_T != 'u' && F_T != 'U' &&
		F_T != 'i')) ? res->size += res->p_width - res->width : 0;
	if (**s == '-')
	{
		ft_putchar(**s);
		(*s)++;
	}
	while (res->p_width-- > n)
		ft_putstr("0");
	return (*s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:27:13 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 14:52:03 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	neg_flg_width(char **format, t_plchdr *res, char *s, int n)
{
	if (res->hash == 1)
		hash_handler(format, res);
	if (res->plus == 1 && res->p == 0 && res->neg == 1)
	{
		ft_putchar('+');
		res->width--;
	}
	if (DIG_MOD)
	{
		while (res->p_width-- > n)
		{
			ft_putchar('0');
			res->width--;
		}
	}
	(res->p == 1) ? put_perc(format, s, res) : write(1, s, n);
	while (n < res->width--)
	{
		res->k = ' ';
		ft_putstr(&res->k);
	}
}

void	pos_flg_width(char **format, t_plchdr *res, char *s, int n)
{
	(res->k == '0' && *s != '-') ? ft_putchar('+') : 0;
	if (*s == '-')
	{
		ft_putchar(*s);
		s++;
	}
	if ((res->hash == 1 && res->p == 1) || (res->plus == 1 && res->neg == 1))
		res->width--;
	(res->hash == 1 && ((**format == 'o') || (**format == 'x') ||
			(**format == 'X'))) ? res->width-- : 0;
	while (n < res->width--)
	{
		ft_putstr(&res->k);
		if (res->width == res->p_width)
			break ;
	}
	(res->hash == 1) ? hash_handler(format, res) : 0;
	if (res->k == ' ' && res->plus == 1 && res->neg != -1 && **format == 'd')
		ft_putchar('+');
	(res->p_width == res->width) ? ft_putchar('0') : 0;
	(res->p == 1) ? put_perc(format, s, res) : 0;
	if (*s == '0')
		NULL;
	else
		write(1, s, n);
}

void	print_edge(char **format, t_plchdr *res, char *s, int n)
{
	if (res->plus == 1 && *s != '\0' && *s != '-' && F_T != 'u' && F_T != 'p' &&
		F_T != 'o' && F_T != 'O' && F_T != 'X' && F_T != 'x' && F_T != 's')
	{
		ft_putchar('+');
		res->size++;
	}
	(res->hash == 1 && *s != '0') ? hash_handler(format, res) : 0;
	if (*s == '0' && res->p == 1 && **format != 'o' && **format != 'O' &&
		res->hash == 1)
		NULL;
	(DIG_MOD) ? edge_num_mod(res, &s, &n) : 0;
	space_flag(format, s, res);
	((**format == 'u' || **format == 'U') && res->width > 1 &&
		res->size < (intmax_t)ft_strlen(s)) ? res->size = ft_strlen(s) : 0;
	if (res->p == 1 && res->p_width > 0)
	{
		while (res->width-- > res->p_width)
			ft_putstr(&res->k);
		perc_p_mod(res, s, format);
		put_perc(format, s, res);
	}
	else if (res->p == 1 && res->p_width <= 0 && *s == '0')
		edge_p_width(format, s, res);
	else
		write(1, s, n);
}

char	*edge_num_mod(t_plchdr *res, char **s, int *n)
{
	while (res->p_width > *n)
	{
		if (**s == '-')
		{
			ft_putchar(**s);
			(*s)++;
			(*n)--;
		}
		else
		{
			res->p_width--;
			ft_putchar('0');
		}
	}
	return (*s);
}

void	edge_p_width(char **format, char *s, t_plchdr *res)
{
	if ((**format == 'o' || **format == 'O') && res->hash == 1)
		ft_putstr(s);
	else
	{
		if (res->hash == 1)
			NULL;
		res->size--;
		NULL;
	}
}

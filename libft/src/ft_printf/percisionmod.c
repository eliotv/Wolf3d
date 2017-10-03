/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percisionmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:33 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 15:27:57 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	**perc_num(char **format, t_plchdr *res, va_list ap)
{
	res->p = 1;
	res->k = ' ';
	(*format)++;
	if (*(*format) == '*')
	{
		(*format)++;
		width_mod(format, ap, res);
	}
	if (NUM_MOD)
		perc_width(format, res);
	return (format);
}

void	put_perc(char **format, char *str, t_plchdr *res)
{
	intmax_t i;
	intmax_t n;

	i = 0;
	n = ft_strlen(str);
	while (res->width > res->p_width && **format == 's')
	{
		if (res->minus == 1)
		{
			while (i < res->p_width && str[i])
				write(1, &str[i++], 1);
		}
		ft_putstr(&res->k);
		res->width--;
	}
	if (**format != 's')
	{
		if (i < res->p_width && str[i])
			write(1, &str[i], n);
	}
	else
		while (i < res->p_width && str[i])
			write(1, &str[i++], 1);
}

int		percision_mod(char **format, t_plchdr *res, char *s, int n)
{
	char *tmp;

	tmp = NULL;
	if (**format == 's' && res->width == 0)
	{
		tmp = ft_strndup(s, res->p_width);
		res->size = ft_strlen(tmp);
	}
	if (res->plus == 1 && res->minus == 0)
	{
		n = res->p_width - 1;
		if (res->hash == 0)
			res->width--;
	}
	if (res->neg != -1 && F_T != 'c' && F_T != 'C')
		res->size = (res->p_width > res->width) ?
			res->p_width : res->width;
	(res->p_width > (intmax_t)ft_strlen(s) && **format == 's' &&
		res->p_width > res->width) ? res->size = (intmax_t)ft_strlen(s) : 0;
	if (DIG_MOD && (intmax_t)ft_strlen(s) > res->p_width)
		res->size = (intmax_t)ft_strlen(s);
	if (res->p_width > res->width && res->width > (intmax_t)ft_strlen(s))
		res->size = res->width;
	(n < 0) ? n = res->p_width : 0;
	return (n);
}

void	perc_p_mod(t_plchdr *res, char *s, char **format)
{
	if (res->p_width > res->width && (F_T == 'p'))
	{
		res->size = res->p_width;
		if (F_T == 'p')
			res->size += 2;
	}
	while (res->p_width > (intmax_t)ft_strlen(s) && F_T != 's')
	{
		ft_putchar('0');
		res->p_width--;
	}
}

char	*perc_p_join(char *s, t_plchdr *res)
{
	char	*tmp;
	char	*str;
	int		i;
	int		k;

	k = 0;
	i = 0;
	str = NULL;
	tmp = NULL;
	if (res->p_width > (intmax_t)ft_strlen(s))
	{
		i = res->p_width - (intmax_t)ft_strlen(s);
		tmp = ft_strnew(i + 1);
		while (i > k)
		{
			tmp[k] = '0';
			k++;
		}
		str = ft_strjoin(tmp, s);
		res->size += (intmax_t)ft_strlen(str);
	}
	return (str);
}

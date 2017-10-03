/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:25 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 14:18:02 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	search_flg_mod(char **format, va_list ap, t_plchdr *res)
{
	while ((FLG_MOD || NUM_MOD || **format == '.' || **format == '*' ||
		L_MOD) && **format)
	{
		if (FLG_MOD)
			flag_finder(format, res);
		if (NUM_MOD)
			get_width_len(format, res);
		if (**format == '.')
			perc_num(format, res, ap);
		if (**format == '*')
			width_mod(format, ap, res);
		if (!F_SPEC)
			length_mod_ck(format, res);
	}
}

void	print_format(char **format, t_plchdr *res)
{
	(**format != '\0' && **format != '%') ? ft_putchar(**format) : 0;
	if (**format && **format != '%')
	{
		res->size++;
		(*format)++;
	}
}

int		search_format(char **format, va_list ap)
{
	t_plchdr	*res;
	int			i;

	i = 0;
	res = NULL;
	res = init_res(res);
	while (**format)
	{
		while (**format == '%')
		{
			i += res->size;
			res = init_res(res);
			(*format)++;
			search_flg_mod(format, ap, res);
			(F_SPEC) ? function_hndlr(format, ap, res) : (res->size = 0);
		}
		print_format(format, res);
	}
	i += res->size;
	free(res);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;

	i = 0;
	va_start(ap, format);
	i = search_format((char**)&format, ap);
	va_end(ap);
	return (i);
}

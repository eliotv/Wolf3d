/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:27 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/09 11:55:09 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	function_hndlr(char **format, va_list ap, t_plchdr *res)
{
	char c;

	c = (**format);
	if (c == 'c' || c == 'C' || c == '%')
		char_conv(format, res, ap);
	if (c == 's' || c == 'S')
		str_conv(format, res, ap);
	if (c == 'd' || c == 'D' || c == 'i')
		dec_conv(format, res, ap);
	if (c == 'u' || c == 'U')
		uint_conv(format, res, ap);
	if (c == 'o' || c == 'O')
		uint_oct_conv(format, res, ap);
	if (c == 'x' || c == 'X')
		uint_hex_conv(format, res, ap, c);
	if (c == 'p')
		pointer_adress(format, res, ap);
	(*format)++;
}

void	flag_finder(char **format, t_plchdr *res)
{
	while (FLG_MOD)
	{
		if (**format == '#')
		{
			res->hash = 1;
			(*format)++;
		}
		if (**format == '-')
			minus_flag(format, res);
		if (**format == '+')
			plus_flag(format, res);
		if (**format == '0')
			zero_flag(format, res);
		if (**format == ' ')
		{
			res->sf = 1;
			res->k = ' ';
			while (**format == ' ')
				(*format)++;
		}
	}
}

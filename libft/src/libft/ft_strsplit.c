/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:24:50 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/22 19:39:33 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int			k;
	int			r;
	char		**ary;
	int			wordcount;

	if (!s || !c)
		return (0);
	wordcount = ft_count_wrd(s, c);
	if (!(ary = ((char**)malloc(sizeof(char*) * (wordcount + 1)))))
		return (NULL);
	r = 0;
	while (wordcount--)
	{
		if (!(ary[r] = ((char*)malloc(sizeof(char) * (ft_count_c(s, c) + 1)))))
			return (NULL);
		k = 0;
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
			ary[r][k++] = *s++;
		ary[r][k] = '\0';
		r++;
	}
	ary[r] = NULL;
	return (ary);
}

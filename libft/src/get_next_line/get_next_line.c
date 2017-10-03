/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:37:02 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/14 18:27:46 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				nl_search(char **str, char **line)
{
	char *newline;
	char *tmp;

	while ((newline = ft_strchr(*str, '\n')))
	{
		*line = ft_strndup(*str, (newline - *str));
		tmp = ft_strdup(newline + 1);
		free(*str);
		*str = tmp;
		return (1);
	}
	if (**str)
	{
		*line = ft_strdup(*str);
		ft_bzero(*str, ft_strlen(*str));
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*str[FD_MAX];
	char		*tmp;
	int			byte_c;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (-1);
	while ((byte_c = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (byte_c == -1)
			return (-1);
		buff[byte_c] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
	}
	if (ft_strlen(str[fd]) > 0)
		return (nl_search(&str[fd], line));
	return (0);
}

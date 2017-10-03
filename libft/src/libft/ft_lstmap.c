/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 09:34:29 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/19 22:32:56 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*save;
	t_list	*current;
	t_list	*new;

	if (!lst)
		return (NULL);
	current = (t_list*)malloc(sizeof(t_list));
	current = f(lst);
	save = current;
	tmp = lst->next;
	while (tmp != NULL)
	{
		new = (t_list*)malloc(sizeof(t_list));
		new = f(tmp);
		tmp = tmp->next;
		current->next = new;
		current = current->next;
		new = NULL;
	}
	return (save);
}

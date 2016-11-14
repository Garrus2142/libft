/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:37:00 by thugo             #+#    #+#             */
/*   Updated: 2016/11/14 10:47:42 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		del(void *elem, size_t size)
{
	free(elem);
	(void)size;
}

static t_list	*lstdel(t_list **list, void (*f)(void *, size_t))
{
	ft_lstdel(list, f);
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_cur;

	if (lst == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		if (new_list == NULL)
		{
			new_list = f(lst);
			if (new_list == NULL)
				return (lstdel(&new_list, &del));
			new_cur = new_list;
		}
		else
		{
			new_cur->next = f(lst);
			if (new_list == NULL)
				return (lstdel(&new_list, &del));
			new_cur = new_cur->next;
		}
		lst = lst->next;
	}
	return (new_list);
}

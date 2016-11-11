/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:46:14 by thugo             #+#    #+#             */
/*   Updated: 2016/11/11 15:34:54 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;
	void		*content_cpy;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		content_cpy = malloc(content_size);
		if (content_cpy == NULL)
		{
			free(list);
			return (NULL);
		}
		list->content = ft_memcpy(content_cpy, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}

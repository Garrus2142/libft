/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 05:05:23 by thugo             #+#    #+#             */
/*   Updated: 2017/02/03 10:45:27 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddsort(t_list **alst, t_list *new, void *param,
			int (*sort)(t_list *new, t_list *next, void *param))
{
	t_list	*prev;
	t_list	*cur;

	if (!alst || !new)
		return ;
	prev = NULL;
	cur = *alst;
	while (cur)
	{
		if (sort(new, cur, param))
		{
			if (!prev)
				*alst = new;
			else
				prev->next = new;
			new->next = cur;
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
	if (!*alst)
		*alst = new;
	else
		prev->next = new;
}

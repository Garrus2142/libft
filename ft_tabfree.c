/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 09:59:38 by thugo             #+#    #+#             */
/*   Updated: 2017/02/03 10:20:01 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_tabfree(void ***tab, size_t size)
{
	size_t	i;

	if (!tab)
		return ;
	i = -1;
	while (++i < size)
		free((*tab)[i]);
	free(*tab);
	*tab = NULL;
}

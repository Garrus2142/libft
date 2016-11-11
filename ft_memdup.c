/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:28:23 by thugo             #+#    #+#             */
/*   Updated: 2016/11/11 17:47:48 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memdup(const void *src, size_t size)
{
	unsigned char	*new;
	size_t			i;

	new = (unsigned char *)malloc(size);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = *((unsigned char *)(src + i));
		i++;
	}
	return ((void *)new);
}

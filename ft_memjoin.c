/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:46:40 by thugo             #+#    #+#             */
/*   Updated: 2017/01/24 17:51:27 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memjoin(void const *s1, size_t l1, void const *s2, size_t l2)
{
	size_t	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (l1 + l2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		((char *)str)[i] = ((char *)s1)[i];
		i++;
	}
	while (i < l1 + l2)
	{
		((char *)str)[i] = ((char *)s2)[i - l1];
		i++;
	}
	return (str);
}

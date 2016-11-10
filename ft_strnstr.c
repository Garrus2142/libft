/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:33:40 by thugo             #+#    #+#             */
/*   Updated: 2016/11/08 20:58:36 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i_big;
	size_t		len_little;

	i_big = 0;
	len_little = ft_strlen(little);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i_big] != '\0' && i_big < len)
	{
		if (big[i_big] == little[0] && i_big + len_little <= len)
		{
			if (ft_strncmp(&big[i_big], little, len_little) == 0)
				return ((char *)&big[i_big]);
		}
		i_big++;
	}
	return (NULL);
}

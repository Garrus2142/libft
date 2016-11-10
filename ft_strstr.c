/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:19:17 by thugo             #+#    #+#             */
/*   Updated: 2016/11/08 20:30:57 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i_big;

	i_big = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i_big] != '\0')
	{
		if (big[i_big] == little[0])
		{
			if (ft_strncmp(&big[i_big], little, ft_strlen(little)) == 0)
				return ((char *)&big[i_big]);
		}
		i_big++;
	}
	return (NULL);
}

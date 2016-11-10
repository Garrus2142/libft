/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:32:16 by thugo             #+#    #+#             */
/*   Updated: 2016/11/08 18:09:46 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_c;
	char	*s_c;
	int		i;

	c_c = (char)c;
	s_c = (char *)s;
	i = 0;
	while (s_c[i] != '\0')
	{
		if (s_c[i] == c_c)
			return (&s_c[i]);
		i++;
	}
	if (s_c[i] == c)
		return (&s_c[i]);
	return (NULL);
}

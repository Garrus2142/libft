/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:13:54 by thugo             #+#    #+#             */
/*   Updated: 2016/11/08 18:15:07 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_c;
	char	*s_c;
	int		i;

	c_c = (char)c;
	s_c = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s_c[i] == c_c)
			return (&s_c[i]);
		i--;
	}
	return (NULL);
}

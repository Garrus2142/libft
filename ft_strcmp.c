/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:25:04 by thugo             #+#    #+#             */
/*   Updated: 2016/11/09 12:04:38 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*s1_c;
	const unsigned char *s2_c;
	int					i;

	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	i = 0;
	while (s1_c[i] != '\0' && s2_c[i] != '\0')
	{
		if (s1_c[i] != s2_c[i])
			return (s1_c[i] - s2_c[i]);
		i++;
	}
	if (s1_c[i] != s2_c[i])
		return (s1_c[i] - s2_c[i]);
	return (0);
}

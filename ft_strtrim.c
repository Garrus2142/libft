/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:08:34 by thugo             #+#    #+#             */
/*   Updated: 2016/11/09 20:38:34 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhite(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (iswhite(s[i]))
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	while (i >= 0 && iswhite(s[i]))
		i--;
	end = i + 1;
	if (start > end)
		return (ft_strnew(0));
	return (ft_strsub(s, (unsigned int)start, (size_t)end - (size_t)start));
}

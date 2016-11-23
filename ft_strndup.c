/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:20:45 by thugo             #+#    #+#             */
/*   Updated: 2016/11/23 11:04:08 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*new;
	int		i;
	size_t	size;

	size = (int)ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (size > len ? len : size) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < (int)len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

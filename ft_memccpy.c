/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:15:44 by thugo             #+#    #+#             */
/*   Updated: 2016/11/07 16:04:07 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_char;
	const unsigned char	*src_char;
	int					i;

	dst_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	i = 0;
	while (i < (int)n)
	{
		dst_char[i] = src_char[i];
		if (src_char[i] == (unsigned char)c)
			return ((void *)&(dst_char[i + 1]));
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:06:37 by thugo             #+#    #+#             */
/*   Updated: 2016/11/07 13:29:55 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}

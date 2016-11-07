/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:07:08 by thugo             #+#    #+#             */
/*   Updated: 2016/11/07 19:45:06 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_c;
	const unsigned char	*src_c;
	size_t				i;

	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	i = 0;
	if (src_c < dst_c)
	{
		while (i < len)
		{
			dst_c[len - (i + 1)] = src_c[len - (i + 1)];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

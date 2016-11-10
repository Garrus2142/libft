/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:55:50 by thugo             #+#    #+#             */
/*   Updated: 2016/11/08 17:30:57 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = 0;
	len_src = ft_strlen(src);
	while (dst[len_dst] != '\0' && len_dst < size)
		len_dst++;
	if (dst[len_dst] != '\0')
		len_dst = size;
	else
		ft_strncat(dst, src, len_dst + 1 > size ? 0 : size - (len_dst + 1));
	return (len_dst + len_src);
}

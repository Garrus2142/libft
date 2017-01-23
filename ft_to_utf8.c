/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_utf8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:47:06 by thugo             #+#    #+#             */
/*   Updated: 2017/01/23 19:06:44 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_to_utf8(int c)
{
	if (c <= 0x7f)
		return ((int)c);
	else if (c <= 0x07ff)
	{
		return ((int)((unsigned char)((c & 0x7c0) >> 6) | 0xc0));
		return ((int)((unsigned char)(c & 0x3f) | 0x80));
	}
	else if (c <= 0xffff)
	{
		return ((int)((unsigned char)((c & 0xf000) >> 12) | 0xe0));
		return ((int)((unsigned char)((c & 0xfc0) >> 6) | 0x80));
		return ((int)((unsigned char)(c & 0x3f) | 0x80));
	}
	else
	{
		return ((int)((unsigned char)((c & 0x1c0000) >> 18) | 0xf0));
		return ((int)((unsigned char)((c & 0x3f000) >> 12) | 0x80));
		return ((int)((unsigned char)((c & 0xfc0) >> 6) | 0x80));
		return ((int)((unsigned char)(c & 0x3f) | 0x80));
	}
}

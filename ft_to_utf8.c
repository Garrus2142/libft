/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_utf8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:47:06 by thugo             #+#    #+#             */
/*   Updated: 2017/01/24 13:12:07 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_to_utf8(int c)
{
	char	*utf8;

	if ((utf8 = ft_strnew(5)) == NULL)
		return (NULL);
	if (c <= 0x7f)
		utf8[0] = (char)c;
	else if (c <= 0x07ff)
	{
		utf8[0] = (char)((unsigned char)((c & 0x7c0) >> 6) | 0xc0);
		utf8[1] = (char)((unsigned char)(c & 0x3f) | 0x80);
	}
	else if (c <= 0xffff)
	{
		utf8[0] = (char)((unsigned char)((c & 0xf000) >> 12) | 0xe0);
		utf8[1] = (char)((unsigned char)((c & 0xfc0) >> 6) | 0x80);
		utf8[2] = (char)((unsigned char)(c & 0x3f) | 0x80);
	}
	else
	{
		utf8[0] = (char)((unsigned char)((c & 0x1c0000) >> 18) | 0xf0);
		utf8[1] = (char)((unsigned char)((c & 0x3f000) >> 12) | 0x80);
		utf8[2] = (char)((unsigned char)((c & 0xfc0) >> 6) | 0x80);
		utf8[3] = (char)((unsigned char)(c & 0x3f) | 0x80);
	}
	return (utf8);
}

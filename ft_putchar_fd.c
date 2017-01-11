/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:23:20 by thugo             #+#    #+#             */
/*   Updated: 2017/01/11 20:56:17 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	uwrite(int fd, unsigned char c)
{
	write(fd, &c, 1);
}

void		ft_putchar_fd(int c, int fd)
{
	if (c <= 0x7f)
		write(fd, &c, 1);
	else if (c <= 0x07ff)
	{
		uwrite(fd, (unsigned char)((c & 0x7c0) >> 6) | 0xc0);
		uwrite(fd, (unsigned char)(c & 0x3f) | 0x80);
	}
	else if (c <= 0xffff)
	{
		uwrite(fd, (unsigned char)((c & 0xf000) >> 12) | 0xe0);
		uwrite(fd, (unsigned char)((c & 0xfc0) >> 6) | 0x80);
		uwrite(fd, (unsigned char)(c & 0x3f) | 0x80);
	}
	else if (c <= 0x10ffff)
	{
		uwrite(fd, (unsigned char)((c & 0x1c0000) >> 18) | 0xf0);
		uwrite(fd, (unsigned char)((c & 0x3f000) >> 12) | 0x80);
		uwrite(fd, (unsigned char)((c & 0xfc0) >> 6) | 0x80);
		uwrite(fd, (unsigned char)(c & 0x3f) | 0x80);
	}
}

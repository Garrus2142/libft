/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:29:07 by thugo             #+#    #+#             */
/*   Updated: 2017/04/13 18:29:25 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	int			retval;
	va_list		ap;

	va_start(ap, format);
	retval = ft_vdprintf(fd, format, &ap);
	va_end(ap);
	return (retval);
}

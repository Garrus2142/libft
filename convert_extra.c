/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:20:33 by thugo             #+#    #+#             */
/*   Updated: 2017/01/27 02:17:56 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static void	process_n(t_parsing *p, va_list *ap)
{
	void	*arg;

	if (p->lmod == LMOD_H && (arg = va_arg(*ap, short *)) != NULL)
		*(short *)arg = (short)buffer_getinfo();
	else if (p->lmod == LMOD_HH && (arg = va_arg(*ap, char *)) != NULL)
		*(char *)arg = (char)buffer_getinfo();
	else if (p->lmod == LMOD_L && (arg = va_arg(*ap, long *)) != NULL)
		*(long *)arg = (long)buffer_getinfo();
	else if (p->lmod == LMOD_LL && (arg = va_arg(*ap, long long *)) != NULL)
		*(long long *)arg = (long long)buffer_getinfo();
	else if (p->lmod == LMOD_J && (arg = va_arg(*ap, intmax_t *)) != NULL)
		*(intmax_t *)arg = (intmax_t)buffer_getinfo();
	else if (p->lmod == LMOD_Z && (arg = va_arg(*ap, size_t *)) != NULL)
		*(size_t *)arg = (size_t)buffer_getinfo();
	else if ((arg = va_arg(*ap, int *)) != NULL)
		*(int *)arg = (int)buffer_getinfo();
}

static void	process_y(t_parsing *p, va_list *ap)
{
	char	*buffer;
	char	**arg;

	buffer = buffer_get();
	if (p->conv_spec == 'y')
	{
		if ((arg = va_arg(*ap, char **)) != NULL)
			*arg = buffer;
	}
	else
		write(va_arg(*ap, int), buffer, buffer_getinfo());
	if (p->attr & ATTR_HASHTAG)
	{
		buffer_clear();
		buffer_init();
	}
}

void		convert_extra(t_parsing *p, va_list *ap, size_t *nbytes)
{
	if (p->conv_spec == 'n')
		process_n(p, ap);
	else if (p->conv_spec == 'y' || p->conv_spec == 'Y')
		process_y(p, ap);
	*nbytes = 0;
}

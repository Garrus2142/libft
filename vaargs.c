/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaargs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 00:26:45 by thugo             #+#    #+#             */
/*   Updated: 2017/01/20 05:24:42 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			get_ll_arg(t_parsing *p, va_list *ap, long long *arg)
{
	if (p->lmod == LMOD_H)
		return ((*arg = (short)va_arg(*ap, int)));
	else if (p->lmod == LMOD_HH)
		return ((*arg = (char)va_arg(*ap, int)));
	else if (p->lmod == LMOD_L)
		return ((*arg = va_arg(*ap, long)));
	else if (p->lmod == LMOD_LL)
		return ((*arg = va_arg(*ap, long long)));
	else if (p->lmod == LMOD_J)
		return ((*arg = va_arg(*ap, intmax_t)));
	else if (p->lmod == LMOD_Z)
		return ((*arg = va_arg(*ap, size_t)));
	else
		return ((*arg = va_arg(*ap, int)));
}

unsigned long long	get_llu_arg(t_parsing *p, va_list *ap,
		unsigned long long *arg)
{
	if (p->lmod == LMOD_H)
		return ((*arg = (unsigned short)va_arg(*ap, unsigned int)));
	else if (p->lmod == LMOD_HH)
		return ((*arg = (unsigned char)va_arg(*ap, unsigned int)));
	else if (p->lmod == LMOD_L)
		return ((*arg = va_arg(*ap, unsigned long)));
	else if (p->lmod == LMOD_LL)
		return ((*arg = va_arg(*ap, unsigned long long)));
	else if (p->lmod == LMOD_J)
		return ((*arg = va_arg(*ap, intmax_t)));
	else if (p->lmod == LMOD_Z)
		return ((*arg = va_arg(*ap, size_t)));
	else
		return ((*arg = va_arg(*ap, unsigned int)));
}

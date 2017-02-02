/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_sc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:40:13 by thugo             #+#    #+#             */
/*   Updated: 2017/01/27 02:10:14 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_c(t_parsing *p, va_list *ap, size_t *nbytes)
{
	char	*c;

	if (p->conv_spec == 'c' && p->lmod != LMOD_L)
	{
		if ((c = (char *)malloc(sizeof(char))) == NULL)
			exit(EXIT_FAILURE);
		*c = (char)va_arg(*ap, int);
		*nbytes = sizeof(char);
	}
	else
	{
		if ((c = ft_to_utf8((int)va_arg(*ap, wchar_t))) == NULL)
			exit(EXIT_FAILURE);
		*nbytes = ft_max(1, (int)ft_strlen((char *)c));
	}
	return (c);
}

static char	*wstr_to_utf8(t_parsing *p, wchar_t *wstr, size_t *nbytes)
{
	char	*s;
	char	*utf8;
	int		i;
	size_t	len;

	i = -1;
	*nbytes = 0;
	if ((s = (char *)malloc(sizeof(wchar_t) * ft_wstrlen(wstr))) == NULL)
		exit(EXIT_FAILURE);
	while (wstr[++i])
	{
		if ((utf8 = ft_to_utf8(wstr[i])) == NULL)
			exit(EXIT_FAILURE);
		len = ft_strlen(utf8);
		if (p->precision > -1 && *nbytes + len > (size_t)p->precision)
		{
			free(utf8);
			break ;
		}
		ft_memcpy(s + *nbytes, utf8, len);
		*nbytes += len;
		free(utf8);
	}
	return (s);
}

static char	*process_s(t_parsing *p, va_list *ap, size_t *nbytes)
{
	char	*s;
	size_t	len;
	void	*arg;

	if (p->conv_spec == 's' && p->lmod != LMOD_L)
	{
		len = p->precision == -1 ? SIZE_MAX : p->precision;
		arg = va_arg(*ap, char *);
		if ((s = ft_strndup((char *)arg == NULL ? "(null)" :
				(char *)arg, len)) == NULL)
			exit(EXIT_FAILURE);
		*nbytes = ft_strlen(s);
	}
	else
	{
		arg = va_arg(*ap, wchar_t *);
		s = wstr_to_utf8(p, (wchar_t *)arg == NULL ? L"(null)" :
			(wchar_t *)arg, nbytes);
	}
	return (s);
}

char		*convert_sc(t_parsing *p, va_list *ap, size_t *nbytes)
{
	char		*str;

	if (p->conv_spec == 'c' || p->conv_spec == 'C')
		str = process_c(p, ap, nbytes);
	else if (p->conv_spec == '%')
	{
		str = (char *)ft_memdup("%", 1);
		*nbytes = 1;
	}
	else
		str = process_s(p, ap, nbytes);
	return (str);
}

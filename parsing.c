/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:59:50 by thugo             #+#    #+#             */
/*   Updated: 2017/01/25 19:56:49 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_attr(const char *format, t_parsing *parsing)
{
	int		i;

	parsing->attr = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '#')
			parsing->attr = parsing->attr | ATTR_HASHTAG;
		else if (format[i] == '0')
			parsing->attr = parsing->attr | ATTR_ZERO;
		else if (format[i] == '-')
			parsing->attr = parsing->attr | ATTR_MINUS;
		else if (format[i] == '+')
			parsing->attr = parsing->attr | ATTR_PLUS;
		else if (format[i] == ' ')
			parsing->attr = parsing->attr | ATTR_SPACE;
		else
			return (i);
		i++;
	}
	return (i);
}

int			parse_field(const char *format, t_parsing *parsing, va_list *ap)
{
	int	i;

	parsing->field_width = 0;
	i = 0;
	if (format[i] == '*')
	{
		parsing->field_width = va_arg(*ap, int);
		if (parsing->field_width < 0)
		{
			parsing->field_width = ft_abs(parsing->field_width);
			parsing->attr = parsing->attr | ATTR_MINUS;
		}
		i++;
	}
	if (ft_isdigit(format[i]))
	{
		parsing->field_width = ft_atoi(format + i);
		while (ft_isdigit(format[++i]) || format[i] == '*')
		{
			if (format[i] == '*')
				return (i + parse_field(format + i, parsing, ap));
		}
	}
	return (i);
}

int			parse_preci(const char *format, t_parsing *parsing, va_list *ap)
{
	int	i;

	parsing->precision = -1;
	i = 0;
	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
			parsing->precision = va_arg(*ap, int);
		else
			parsing->precision = ft_atoi(format + i);
		if (parsing->precision < 0)
			parsing->precision = -1;
		while (ft_isdigit(format[i]) || format[i] == '*')
			i++;
	}
	return (i);
}

int			parse_lenmodif(const char *format, t_parsing *parsing)
{
	int	i;

	i = 0;
	parsing->lmod = -1;
	while (format[i])
	{
		if (format[i + 1] == 'h' && format[i] == 'h')
			parsing->lmod = LMOD_HH;
		else if (format[i] == 'h')
			parsing->lmod = LMOD_H;
		else if (format[i + 1] == 'l' && format[i] == 'l')
			parsing->lmod = LMOD_LL;
		else if (format[i] == 'l')
			parsing->lmod = LMOD_L;
		else if (format[i] == 'j')
			parsing->lmod = LMOD_J;
		else if (format[i] == 'z')
			parsing->lmod = LMOD_Z;
		else
			return (i);
		if (parsing->lmod == LMOD_HH || parsing->lmod == LMOD_LL)
			i++;
		i++;
	}
	return (i);
}

int			parse_format(const char *format, t_parsing *parsing, va_list *ap)
{
	int		i;

	i = 0;
	i += parse_attr(format, parsing);
	i += parse_field(format + i, parsing, ap);
	i += parse_preci(format + i, parsing, ap);
	i += parse_lenmodif(format + i, parsing);
	parsing->conv_spec = -1;
	if (format[i] != '\0')
	{
		parsing->conv_spec = format[i];
		if (parsing->conv_spec == 'p')
			parsing->lmod = LMOD_LL;
		i++;
	}
	return (i);
}

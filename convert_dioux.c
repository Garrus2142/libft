/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:05:30 by thugo             #+#    #+#             */
/*   Updated: 2017/01/25 23:26:53 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

static void	process_dioux_hash(t_parsing *p, char **str, size_t *nbytes,
		unsigned long long arg)
{
	char	*join;

	if ((p->conv_spec == 'o' || p->conv_spec == 'O') &&
			(*nbytes == 0 || (*str)[0] != '0'))
	{
		if ((join = ft_strnew(1)) == NULL)
			exit(EXIT_FAILURE);
		join[0] = '0';
		if ((*str = ft_strfjoin(join, 1, *str, 1)) == NULL)
			exit(EXIT_FAILURE);
		*nbytes += 1;
	}
	else if (((p->conv_spec == 'x' || p->conv_spec == 'X') && arg > 0)
		|| p->conv_spec == 'p')
	{
		if ((join = ft_strnew(2)) == NULL)
			exit(EXIT_FAILURE);
		ft_strcpy(join, p->conv_spec == 'X' ? "0X" : "0x");
		if ((*str = ft_strfjoin(join, 1, *str, 1)) == NULL)
			exit(EXIT_FAILURE);
		*nbytes += 2;
	}
}

static void	process_precision(t_parsing *p, char **str, size_t *nbytes,
		unsigned long long arg)
{
	int		neg;
	char	*join;

	neg = 0;
	if (p->precision == 0 && arg == 0)
		(*str)[--(*nbytes)] = '\0';
	else if (p->precision > 0 && (int)(p->precision - *nbytes) +
			((*str)[0] == '-' ? 1 : 0) > 0)
	{
		if ((*str)[0] == '-')
			neg = 1;
		if ((join = ft_strnew((neg ? 1 : 0) + (int)(p->precision - *nbytes)))
				== NULL)
			exit(EXIT_FAILURE);
		ft_memset(join, '0', (neg ? 1 : 0) + (int)(p->precision - *nbytes));
		if (neg)
		{
			(*str)[0] = '0';
			join[0] = '-';
		}
		if ((*str = ft_strfjoin(join, 1, *str, 1)) == NULL)
			exit(EXIT_FAILURE);
		*nbytes += (neg ? 1 : 0) + (int)(p->precision - *nbytes);
	}
}

static void	process_dioux_zero(t_parsing *p, char **str, size_t *nbytes,
		unsigned long long arg)
{
	if (p->field_width == 0)
		p->precision = 1;
	else
	{
		p->precision = p->field_width;
		if ((p->attr & ATTR_HASHTAG && (arg != 0 && (p->conv_spec == 'x'
				|| p->conv_spec == 'X'))) || p->conv_spec == 'p')
			p->precision -= 2;
		if ((p->attr & ATTR_SPACE || p->attr & ATTR_PLUS || (*str)[0] == '-') &&
				ft_strchr("diD", p->conv_spec))
			p->precision--;
	}
	process_precision(p, str, nbytes, arg);
}

static void	process_dioux(t_parsing *p, char **str, unsigned long long arg,
		size_t *nbytes)
{
	char	*join;

	*nbytes = ft_strlen(*str);
	process_precision(p, str, nbytes, arg);
	if (p->precision > -1 && p->attr & ATTR_ZERO)
		p->attr = p->attr & 0xfd;
	if (p->attr & ATTR_ZERO && p->precision == -1 && !(p->attr & ATTR_MINUS))
		process_dioux_zero(p, str, nbytes, arg);
	if (p->attr & ATTR_HASHTAG || p->conv_spec == 'p')
		process_dioux_hash(p, str, nbytes, arg);
	if ((p->attr & ATTR_SPACE || p->attr & ATTR_PLUS) && (p->conv_spec == 'd' ||
			p->conv_spec == 'i' || p->conv_spec == 'D') && (*str)[0] != '-')
	{
		if ((join = ft_strnew(1)) == NULL)
			exit(EXIT_FAILURE);
		join[0] = p->attr & ATTR_PLUS ? '+' : ' ';
		if ((*str = ft_strfjoin(join, 1, *str, 1)) == NULL)
			exit(EXIT_FAILURE);
		*nbytes += 1;
	}
}

char		*convert_dioux(t_parsing *p, va_list *ap, size_t *nbytes)
{
	char				base[17];
	char				*str;
	unsigned long long	arg;

	if (p->conv_spec == 'o' || p->conv_spec == 'O')
		ft_strcpy(base, "01234567");
	else if (p->conv_spec == 'x' || p->conv_spec == 'p')
		ft_strcpy(base, "0123456789abcdef");
	else if (p->conv_spec == 'X')
		ft_strcpy(base, "0123456789ABCDEF");
	else if (p->conv_spec == 'b')
		ft_strcpy(base, "01");
	else
		ft_strcpy(base, "0123456789");
	if (p->conv_spec == 'D' || p->conv_spec == 'O' || p->conv_spec == 'U')
		p->lmod = p->lmod == LMOD_LL ? LMOD_LL : LMOD_L;
	if (p->conv_spec == 'd' || p->conv_spec == 'D' || p->conv_spec == 'i')
		str = ft_llitoa_base(get_ll_arg(p, ap, (long long *)&arg), base);
	else
		str = ft_lluitoa_base(get_llu_arg(p, ap, &arg), base);
	if (str == NULL)
		exit(EXIT_FAILURE);
	process_dioux(p, &str, arg, nbytes);
	return (str);
}

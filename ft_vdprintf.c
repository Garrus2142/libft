/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:26:34 by thugo             #+#    #+#             */
/*   Updated: 2017/11/02 20:30:03 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static char	*process_field_width(t_parsing *p, char *str, size_t *nbytes)
{
	long long	num_space;
	char		*spaces;
	char		*new;

	num_space = (long long)p->field_width - (long long)*nbytes;
	if (num_space <= 0)
		return (str);
	if ((spaces = (char *)malloc(sizeof(char) * num_space)) == NULL)
		exit(EXIT_FAILURE);
	if (p->attr & ATTR_MINUS)
	{
		ft_memset(spaces, ' ', num_space);
		if ((new = (char *)ft_memjoin(str, *nbytes, spaces, num_space)) == NULL)
			exit(EXIT_FAILURE);
	}
	else
	{
		ft_memset(spaces, (p->attr & ATTR_ZERO) ? '0' : ' ', num_space);
		if ((new = (char *)ft_memjoin(spaces, num_space, str, *nbytes)) == NULL)
			exit(EXIT_FAILURE);
	}
	*nbytes += num_space;
	free(spaces);
	free(str);
	return (new);
}

static void	process_conv(t_buffer *buff, t_parsing *p, va_list *ap)
{
	size_t	nbytes;
	char	*str;

	str = NULL;
	nbytes = 0;
	if (ft_strchr("dDioOuUxXbp", p->conv_spec))
		str = convert_dioux(p, ap, &nbytes);
	else if (ft_strchr("cCsS%", p->conv_spec))
		str = convert_sc(p, ap, &nbytes);
	else if (ft_strchr("n", p->conv_spec))
		convert_extra(buff, p, ap, &nbytes);
	else if (p->conv_spec != -1)
	{
		if ((str = (char *)malloc(sizeof(char))) == NULL)
			exit(EXIT_FAILURE);
		str[0] = p->conv_spec;
		nbytes = 1;
	}
	if (p->field_width > 0)
		str = process_field_width(p, str, &nbytes);
	if (nbytes > 0)
		buffer_add(buff, str, nbytes);
	if (str != NULL)
		free(str);
}

static void	process_format(t_buffer *buff, const char *format, va_list *ap)
{
	t_parsing	p;
	int			i;
	int			s_start;

	i = -1;
	s_start = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			if (s_start > -1)
				buffer_add(buff, format + s_start, (size_t)i - s_start);
			s_start = -1;
			if (format[i + 1] == '\0')
				break ;
			i += parse_format(format + i + 1, &p, ap);
			process_conv(buff, &p, ap);
		}
		else if (s_start == -1)
			s_start = i;
	}
	if (s_start > -1)
		buffer_add(buff, format + s_start, (size_t)i - s_start);
}

int			ft_vdprintf(int fd, const char *format, va_list *ap)
{
	size_t		nbytes;
	char		*str;
	t_buffer	buff;

	buffer_init(&buff);
	process_format(&buff, format, ap);
	nbytes = buffer_getinfo(&buff);
	str = buffer_get(&buff);
	buffer_clear(&buff);
	if (nbytes > 0)
		write(fd, str, nbytes);
	free(str);
	return (nbytes);
}

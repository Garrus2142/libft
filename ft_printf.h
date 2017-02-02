/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:43:19 by thugo             #+#    #+#             */
/*   Updated: 2017/02/02 14:20:12 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ATTR_HASHTAG 1
# define ATTR_ZERO 2
# define ATTR_MINUS 4
# define ATTR_PLUS 8
# define ATTR_SPACE 16
# define LMOD_HH 0
# define LMOD_H 1
# define LMOD_L 2
# define LMOD_LL 3
# define LMOD_J 4
# define LMOD_Z 5

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_parsing
{
	char	attr;
	int		field_width;
	int		precision;
	char	lmod;
	char	conv_spec;
}					t_parsing;

typedef struct		s_buffer
{
	t_list		*buffer;
	size_t		size_bytes;
}					t_buffer;

int					parse_format(const char *format, t_parsing *parsing,
						va_list *ap);
void				buffer_init();
void				buffer_add(const void *content, size_t size);
char				*buffer_get(void);
size_t				buffer_getinfo(void);
void				buffer_clear(void);
char				*convert_dioux(t_parsing *p, va_list *ap,
						size_t *nbytes);
char				*convert_sc(t_parsing *p, va_list *ap,
						size_t *nbytes);
void				convert_extra(t_parsing *p, va_list *ap,
						size_t *nbytes);
long long			get_ll_arg(t_parsing *p, va_list *ap, long long *arg);
unsigned long long	get_llu_arg(t_parsing *p, va_list *ap,
		unsigned long long *arg);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffermanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:11:05 by thugo             #+#    #+#             */
/*   Updated: 2017/11/02 20:24:53 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buffer_init(t_buffer *buff)
{
	buff->buffer = NULL;
	buff->size_bytes = 0;
}

void	buffer_add(t_buffer *buff, const void *content, size_t size)
{
	t_list	*el;

	if (content == NULL)
		return ;
	el = ft_lstnew(content, size);
	if (el == NULL)
		exit(EXIT_FAILURE);
	ft_lstinsert(&(buff->buffer), el);
	buff->size_bytes += size;
}

char	*buffer_get(t_buffer *buff)
{
	t_list	*cur;
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * buff->size_bytes + 1);
	if (str == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	cur = buff->buffer;
	while (cur)
	{
		ft_memcpy(str + i, cur->content, cur->content_size);
		i += cur->content_size;
		cur = cur->next;
	}
	str[i] = '\0';
	return (str);
}

size_t	buffer_getinfo(t_buffer *buff)
{
	return (buff->size_bytes);
}

void	buffer_clear(t_buffer *buff)
{
	t_list	*cur;
	t_list	*next;

	cur = buff->buffer;
	while (cur)
	{
		next = cur->next;
		free(cur->content);
		free(cur);
		cur = next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffermanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:11:05 by thugo             #+#    #+#             */
/*   Updated: 2017/01/24 18:08:49 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_buffer	g_b;

void	buffer_init(void)
{
	g_b.buffer = NULL;
	g_b.size_bytes = 0;
}

void	buffer_add(const void *content, size_t size)
{
	t_list	*el;

	if (content == NULL)
		return ;
	el = ft_lstnew(content, size);
	if (el == NULL)
		exit(EXIT_FAILURE);
	ft_lstinsert(&(g_b.buffer), el);
	g_b.size_bytes += size;
}

char	*buffer_get(void)
{
	t_list	*cur;
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * g_b.size_bytes + 1);
	if (str == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	cur = g_b.buffer;
	while (cur)
	{
		ft_memcpy(str + i, cur->content, cur->content_size);
		i += cur->content_size;
		cur = cur->next;
	}
	str[i] = '\0';
	return (str);
}

size_t	buffer_getinfo(void)
{
	return (g_b.size_bytes);
}

void	buffer_clear(void)
{
	t_list	*cur;
	t_list	*next;

	cur = g_b.buffer;
	while (cur)
	{
		next = cur->next;
		free(cur->content);
		free(cur);
		cur = next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <thugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:27:46 by thugo             #+#    #+#             */
/*   Updated: 2017/10/23 17:28:06 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static t_list	*get_elem(t_list *lst, int fd)
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		if (((t_gnl *)current->content)->fd == fd)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static void		del_elem(t_list **lst, t_list *elem)
{
	t_list	*prev;
	t_list	*cur;

	prev = NULL;
	cur = *lst;
	if (elem == *lst)
		*lst = elem->next;
	else
	{
		while (cur != NULL)
		{
			if (cur == elem && prev != NULL)
			{
				prev->next = elem->next;
				cur = NULL;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
	}
	free(elem->content);
	free(elem);
}

static int		read_buffer(char **line, char *buffer)
{
	int		i;
	char	*oldptr;

	i = -1;
	while (++i != -1)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			oldptr = *line;
			*line = ft_strnjoin(*line, buffer, i);
			free(oldptr);
			if (*line == NULL)
				return (-1);
			if (buffer[i] == '\n')
			{
				ft_memmove(buffer, &(buffer[i + 1]), BUFF_SIZE - (size_t)i);
				return (1);
			}
			buffer[0] = '\0';
			i = -2;
		}
	}
	return (0);
}

static int		reader(const int fd, char **line, char *buffer)
{
	size_t		res;
	int			res_buffer;

	res = 1;
	if ((*line = ft_strnew(0)) == NULL)
		return (-1);
	while (res != 0)
	{
		if ((res_buffer = read_buffer(line, buffer)) == 1 || res_buffer == -1)
			return (res_buffer);
		res = read(fd, buffer, BUFF_SIZE);
		if (res == (size_t)-1)
		{
			ft_memdel((void **)line);
			return (-1);
		}
		buffer[res] = '\0';
	}
	if (*line[0] != '\0')
		return (1);
	return (0);
}

int				ft_gnl(const int fd, char **line)
{
	static t_list	*lstfd;
	t_list			*elem;
	t_gnl			gnl;
	int				res_reader;

	if (line == NULL)
		return (-1);
	if ((elem = get_elem(lstfd, fd)) == NULL)
	{
		gnl.fd = fd;
		gnl.buffer[0] = '\0';
		elem = ft_lstnew(&gnl, sizeof(gnl));
		if (elem == NULL)
			return (-1);
		ft_lstadd(&lstfd, elem);
	}
	if ((res_reader = reader(fd, line, ((t_gnl *)elem->content)->buffer)) == 0)
	{
		ft_memdel((void **)line);
		del_elem(&lstfd, elem);
		return (0);
	}
	if (res_reader == -1)
		del_elem(&lstfd, elem);
	return (res_reader);
}

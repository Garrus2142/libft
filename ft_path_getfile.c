/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_getfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:11:29 by thugo             #+#    #+#             */
/*   Updated: 2017/02/20 08:16:48 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_path_getfile(const char *path)
{
	int	iend;
	int	istart;
	int	i;
	int	hasslash;

	if (!path)
		return (NULL);
	i = ft_strlen(path);
	istart = 0;
	iend = -1;
	hasslash = 0;
	while (--i >= 0 && !istart)
	{
		if (iend == -1 && path[i] != '/')
			iend = i;
		else if (iend > -1 && path[i] == '/' && !hasslash)
			hasslash = 1;
		if (iend > -1 && hasslash && path[i] == '/')
			istart = i + 1;
	}
	if (iend == -1)
		return (ft_strdup(path));
	else
		return (ft_strndup(path + istart, iend - (istart - 1)));
}

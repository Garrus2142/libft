/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 22:09:39 by thugo             #+#    #+#             */
/*   Updated: 2017/02/03 13:36:11 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strfjoin(char *s1, int f1, char *s2, int f2)
{
	char	*str;

	if (!(str = ft_strjoin(s1, s2)))
		return (NULL);
	if (f1)
		free(s1);
	if (f2)
		free(s2);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <thugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:21:59 by thugo             #+#    #+#             */
/*   Updated: 2017/10/31 18:28:05 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strfdup(char *s)
{
	char	*dup;

	if (!s)
		return (NULL);
	dup = ft_strdup(s);
	free(s);
	return (dup);
}

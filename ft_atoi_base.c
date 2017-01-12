/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:19:07 by thugo             #+#    #+#             */
/*   Updated: 2017/01/12 12:15:04 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> //REMOVE

static int	base_check(const char *base, int *b_size)
{
	int	i1;
	int	i2;

	i1 = 0;
	while (base[i1] != '\0')
	{
		if (base[i1] == '+' || base[i1] == '-')
			return (0);
		i2 = 0;
		while (base[i2] != '\0')
		{
			if (base[i2] == base[i1] && i2 != i1)
				return (0);
			i2++;
		}
		i1++;
	}
	*b_size = ft_strlen(base);
	return (1);
}

int			ft_atoi_base(const char *str, const char *base)
{
	int	b_size;

	if (!base_check(base, &b_size))
		return (0);
	
	return (0);
}

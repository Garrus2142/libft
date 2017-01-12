/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:19:07 by thugo             #+#    #+#             */
/*   Updated: 2017/01/12 14:33:30 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_check(const char *base, int *b_size)
{
	int	i1;
	int	i2;

	if ((*b_size = ft_strlen(base)) < 2)
		return (0);
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
	return (1);
}

int			ft_atoi_base(const char *str, const char *base)
{
	int	b_size;
	int	i;
	int	res;
	int	rank;

	if (!base_check(base, &b_size))
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_strchr(base, str[i]))
		i++;
	if (str[i] != '\0' || (i - 1) < 0 || str[i - 1] == '+' || str[i - 1] == '-')
		return (0);
	res = 0;
	rank = 0;
	while (--i >= (str[0] == '+' || str[0] == '-') ? 1 : 0)
	{
		res -= ft_pow(b_size, rank) * (int)(ft_strchr(base, str[i]) - base);
		rank++;
	}
	return (str[0] == '-' ? res * 1 : res * -1);
}

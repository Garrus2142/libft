/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:55:30 by thugo             #+#    #+#             */
/*   Updated: 2017/01/19 01:13:48 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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

char		*ft_itoa_base(int nbr, const char *base)
{
	int		b_size;
	int		str_size;
	int		res_div;
	int		i;
	char	*str;

	if (!base_check(base, &b_size))
		return (NULL);
	str_size = ft_is_negative(nbr) ? 2 : 1;
	nbr = nbr > 0 ? nbr * -1 : nbr;
	res_div = nbr;
	while ((res_div = res_div / b_size) < 0)
		str_size++;
	if (!(str = ft_strnew(str_size)))
		return (NULL);
	str[0] = ft_is_negative(nbr) ? '-' : '0';
	res_div = nbr;
	i = 0;
	while (res_div < 0)
	{
		str[str_size - (1 + i)] = base[(res_div % b_size) * -1];
		res_div = res_div / b_size;
		i++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 00:58:02 by thugo             #+#    #+#             */
/*   Updated: 2017/01/19 01:15:09 by thugo            ###   ########.fr       */
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

char		*ft_lluitoa_base(unsigned long long nbr, const char *base)
{
	int					b_size;
	int					str_size;
	unsigned long long	res_div;
	int					i;
	char				*str;

	if (!base_check(base, &b_size))
		return (NULL);
	str_size = 1;
	res_div = nbr;
	while ((res_div = res_div / b_size) > 0)
		str_size++;
	if (!(str = ft_strnew(str_size)))
		return (NULL);
	str[0] = '0';
	res_div = nbr;
	i = 0;
	while (res_div > 0)
	{
		str[str_size - (1 + i)] = base[res_div % b_size];
		res_div = res_div / b_size;
		i++;
	}
	return (str);
}

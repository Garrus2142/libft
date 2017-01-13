/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:56:46 by thugo             #+#    #+#             */
/*   Updated: 2017/01/13 15:56:48 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		div;
	int		res;
	int		i;

	res = n > 0 ? n * -1 : n;
	div = 1;
	i = n < 0 ? 2 : 1;
	while (res / div < -10)
	{
		div *= 10;
		i++;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[0] = '-';
	i = n < 0 ? 1 : 0;
	while (div > 0)
	{
		str[i] = ft_abs(res / div) + '0';
		res -= (res / div) * div;
		div /= 10;
		i++;
	}
	return (str);
}

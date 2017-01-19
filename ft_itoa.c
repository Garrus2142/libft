/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:56:46 by thugo             #+#    #+#             */
/*   Updated: 2017/01/19 04:59:35 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa(int n)
{
	int		str_size;
	int		res_div;
	int		i;
	char	*str;

	str_size = ft_is_negative(n) ? 2 : 1;
	n = ft_is_negative(n) ? n : n * -1;
	res_div = n;
	while ((res_div = res_div / 10) < 0)
		str_size++;
	if (!(str = ft_strnew(str_size)))
		return (NULL);
	str[0] = ft_is_negative(n) ? '-' : '0';
	res_div = n;
	i = 0;
	while (res_div < 0)
	{
		str[str_size - (1 + i)] = '0' + ((res_div % 10) * -1);
		res_div = res_div / 10;
		i++;
	}
	return (str);
}

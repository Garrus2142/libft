/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:39:55 by thugo             #+#    #+#             */
/*   Updated: 2016/11/09 17:20:15 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		res;
	int		i;
	int		negate;
	int		reading;

	res = 0;
	i = 0;
	negate = 0;
	reading = 0;
	while (str[i] != '\0' && reading != -1)
	{
		if (ft_isdigit(str[i]))
		{
			reading = 1;
			res *= 10;
			res += str[i] - '0';
		}
		else if (!reading && negate == 0 && (str[i] == '+' || str[i] == '-'))
			negate = str[i] == '-' ? 1 : -1;
		else if (!ft_isspace(str[i]) || reading == 1 || negate != 0)
			reading = -1;
		i++;
	}
	return (negate == 1 ? (int)res * -1 : (int)res);
}

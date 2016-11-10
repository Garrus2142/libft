/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:57:37 by thugo             #+#    #+#             */
/*   Updated: 2016/11/10 19:31:32 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(int a, int b)
{
	int		i;
	int		res;

	i = 1;
	res = a;
	if (b <= 0)
		return (1);
	else if (b == 1)
		return (a);
	while (i < b)
	{
		res *= a;
		i++;
	}
	return (res);
}

static int	count_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n == FT_INT_MIN)
		return (10);
	n = ft_abs(n);
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	convert(char *str, int n, int size)
{
	int		i;
	int		divide;

	i = 0;
	if (n < 0)
		str[i++] = '-';
	n = ft_abs(n);
	divide = power(10, size - 1);
	while (divide > 0)
	{
		str[i] = (n / divide) + '0';
		n -= (n / divide) * divide;
		divide /= 10;
		i++;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = count_size(n);
	str = ft_strnew((size_t)size + (n < 0 ? 1 : 0));
	if (str == NULL)
		return (NULL);
	if (n == FT_INT_MIN)
		return (ft_strcpy(str, "-2147483648"));
	convert(str, n, size);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:27:38 by thugo             #+#    #+#             */
/*   Updated: 2016/11/11 19:12:58 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_divide(int n)
{
	int	divide;

	n = ft_abs(n);
	divide = 1;
	while (n > 9)
	{
		n /= 10;
		divide *= 10;
	}
	return (divide);
}

void		ft_putnbr_fd(int n, int fd)
{
	int	divide;

	if (n == FT_INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	n = ft_abs(n);
	divide = get_divide(n);
	while (divide > 0)
	{
		ft_putchar_fd((n / divide) + '0', fd);
		n -= (n / divide) * divide;
		divide /= 10;
	}
}

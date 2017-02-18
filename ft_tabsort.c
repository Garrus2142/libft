/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:53:34 by thugo             #+#    #+#             */
/*   Updated: 2017/02/18 15:18:04 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(char **s1, char **s2)
{
	char	*swap;

	swap = *s1;
	*s1 = *s2;
	*s2 = swap;
}

char		**ft_tabsort(char **tab, size_t size,
		int (*sort)(const char *s1, const char *s2))
{
	size_t	i;
	int		nswap;

	nswap = 1;
	while (nswap)
	{
		i = 0;
		nswap = 0;
		while (i < size - 1)
		{
			if (sort(tab[i], tab[i + 1]) > 0)
			{
				swap(tab + i, tab + i + 1);
				++nswap;
			}
			++i;
		}
	}
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:38:52 by thugo             #+#    #+#             */
/*   Updated: 2016/11/11 09:57:17 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		count_size(char const *s, char c)
{
	int	size;

	size = 0;
	while (s[size] != c && s[size] != '\0')
		size++;
	return (size);
}

static int		count_split(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			i += count_size(&s[i], c) - 1;
		}
		i++;
	}
	return (count);
}

static int		free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static int		split(char **tab, char const *s, char c)
{
	int		i;
	int		word;
	int		size;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			size = count_size(&s[i], c);
			tab[word] = ft_strsub(s, i, size);
			if (tab[word] == NULL)
				return (free_tab(tab));
			i += size - 1;
			word++;
		}
		i++;
	}
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		count;

	if (s == NULL)
		return (NULL);
	count = count_split(s, c);
	tab = (char **)malloc(sizeof(char *) * ((size_t)count + 1));
	if (tab == NULL)
		return (NULL);
	tab[count] = NULL;
	if (!split(tab, s, c))
		return (NULL);
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <thugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 02:43:16 by thugo             #+#    #+#             */
/*   Updated: 2017/11/02 02:43:17 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		count_size(char const *s, char *c)
{
	int	size;

	size = 0;
	while (!ft_strchr(c, s[size]) && s[size] != '\0')
		size++;
	return (size);
}

static int		count_split(char const *s, char *c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (!ft_strchr(c, s[i]))
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

static int		split(char **tab, char const *s, char *c)
{
	int		i;
	int		word;
	int		size;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (!ft_strchr(c, s[i]))
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

char			**ft_strsplits(char const *s, char *c)
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

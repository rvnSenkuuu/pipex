/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 23:38:20 by tkara2            #+#    #+#             */
/*   Updated: 2024/06/16 23:39:16 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

static size_t	ft_issep(char c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && ft_issep(s[i], c))
		i++;
	while (s[i])
	{
		if ((!ft_issep(s[i], c) && ft_issep(s[i + 1], c))
			|| (!s[i + 1] && !ft_issep(s[i], c)))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strdupsep(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	*dup;

	i = 0;
	j = 0;
	while (!ft_issep(s[j], c))
		j++;
	dup = (char *)ft_calloc(sizeof(char), (j + 1));
	if (!dup)
		return (NULL);
	while (i < j)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**output;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	output = (char **)ft_calloc(sizeof(char *), (ft_countword(s, c) + 1));
	if (!output)
		return (NULL);
	while (s[i])
	{
		if (ft_issep(s[i], c))
			i++;
		else
		{
			output[j] = ft_strdupsep(&s[i], c);
			if (!output[j])
				return (ft_free_doubletab(output), NULL);
			i += ft_strlen(output[j]);
			j++;
		}
	}
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:54:24 by tkara2            #+#    #+#             */
/*   Updated: 2024/04/15 18:54:51 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	s1_len;

	start = 0;
	end = 0;
	s1_len = ft_strlen(s1);
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	while (s1[s1_len - end - 1] && ft_isset(s1[s1_len - end - 1], set))
		end++;
	return (ft_substr(s1, start, s1_len - (start + end)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:13:39 by tkara2            #+#    #+#             */
/*   Updated: 2024/06/16 21:21:47 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *neddle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (neddle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == neddle[j] && (i + j) < len)
		{
			if (haystack[i + j] == '\0' && neddle[j] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		if (neddle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

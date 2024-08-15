/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:44:37 by tkara2            #+#    #+#             */
/*   Updated: 2024/04/12 01:14:44 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (size <= dest_len)
		return (src_len + size);
	else
	{
		i = 0;
		while (src[i] && (dest_len + i) < size - 1)
		{
			dst[dest_len + i] = src[i];
			i++;
		}
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

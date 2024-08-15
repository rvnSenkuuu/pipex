/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:14:08 by tkara2            #+#    #+#             */
/*   Updated: 2024/04/20 19:24:32 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy_s;
	unsigned char	*cpy_d;

	cpy_s = (unsigned char *)src;
	cpy_d = (unsigned char *)dest;
	if (dest > src)
	{
		while (n > 0)
		{
			cpy_d[n - 1] = cpy_s[n - 1];
			--n;
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}

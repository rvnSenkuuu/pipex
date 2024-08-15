/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 00:42:28 by tkara2            #+#    #+#             */
/*   Updated: 2024/04/23 22:28:02 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

static size_t	ft_digit_count(long int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	nb;
	size_t		len;
	char		*output;

	nb = n;
	len = ft_digit_count(nb);
	output = malloc(sizeof(char) * len + 1);
	if (!output)
		return (NULL);
	output[len] = '\0';
	len--;
	if (nb == 0)
		output[0] = '0';
	if (n < 0)
	{
		output[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		output[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (output);
}

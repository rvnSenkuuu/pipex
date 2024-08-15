/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:31:51 by tkara2            #+#    #+#             */
/*   Updated: 2024/06/16 22:36:09 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/libft.h"

int	ft_pf_putnbr_uint(unsigned int n)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = n;
	if (nb > 9)
		len += ft_pf_putnbr_uint(nb / 10);
	len += ft_pf_putchar((nb % 10) + '0');
	return (len);
}

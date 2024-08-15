/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:37:32 by tkara2            #+#    #+#             */
/*   Updated: 2024/06/16 22:35:42 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/libft.h"

int	ft_pf_putnbr_hex(unsigned long long int n, char format)
{
	int		len;
	char	*base;

	len = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		len += ft_pf_putnbr_hex(n / 16, format);
	len += ft_pf_putchar(base[n % 16]);
	return (len);
}

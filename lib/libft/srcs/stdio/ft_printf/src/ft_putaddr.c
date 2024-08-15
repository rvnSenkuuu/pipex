/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:10:53 by tkara2            #+#    #+#             */
/*   Updated: 2024/05/29 18:05:39 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

int	ft_putaddr(unsigned long long int ptr)
{
	int		len;
	char	*base;

	base = "0123456789abcdef";
	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"), 5);
	if (ptr >= 16)
		len += ft_putaddr(ptr / 16);
	len += ft_putchar(base[ptr % 16]);
	return (len);
}

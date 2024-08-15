/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:18:29 by tkara2            #+#    #+#             */
/*   Updated: 2024/05/29 18:05:03 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
		return (write(STDOUT_FILENO, "(null)", 6));
	write(STDOUT_FILENO, s, ft_strlen(s));
	return (ft_strlen(s));
}

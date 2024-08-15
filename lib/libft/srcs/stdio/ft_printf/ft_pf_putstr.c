/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:18:29 by tkara2            #+#    #+#             */
/*   Updated: 2024/06/16 22:36:29 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/libft.h"

int	ft_pf_putstr(char *s)
{
	if (!s)
		return (write(STDOUT_FILENO, "(null)", 6));
	write(STDOUT_FILENO, s, ft_pf_strlen(s));
	return (ft_pf_strlen(s));
}

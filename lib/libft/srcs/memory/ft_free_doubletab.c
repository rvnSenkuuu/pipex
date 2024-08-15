/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_doubletab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:35:29 by tkara2            #+#    #+#             */
/*   Updated: 2024/05/23 16:38:24 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

void	ft_free_doubletab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
	{
		(free(tab[i]), tab[i] = NULL);
		i++;
	}
	(free(tab), tab = NULL);
}

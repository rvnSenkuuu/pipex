/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:27:09 by tkara2            #+#    #+#             */
/*   Updated: 2024/04/14 14:28:37 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*output;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	output = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!output)
		return (NULL);
	while (i < s1_len)
	{
		output[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
		output[s1_len++] = s2[i++];
	output[s1_len] = '\0';
	return (output);
}

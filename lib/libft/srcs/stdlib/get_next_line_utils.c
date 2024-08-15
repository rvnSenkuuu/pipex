/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:46:51 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/17 17:15:38 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*output;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	output = ft_calloc((s1_len + s2_len) + 1, sizeof(char));
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
	return (free(s1), output);
}

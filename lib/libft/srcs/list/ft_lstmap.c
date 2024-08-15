/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:01:33 by tkara2            #+#    #+#             */
/*   Updated: 2024/04/22 17:01:45 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*output_lst;
	t_list	*output_node;

	output_lst = NULL;
	while (lst)
	{
		output_node = ft_lstnew(f(lst->content));
		if (!output_node)
		{
			ft_lstclear(&output_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&output_lst, output_node);
		lst = lst->next;
	}
	return (output_lst);
}

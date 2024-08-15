/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:01:10 by tkara2            #+#    #+#             */
/*   Updated: 2024/08/13 11:44:05 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	print_err(char *s_err)
{
	write(STDERR_FILENO, s_err, ft_strlen(s_err));
	exit(FAILURE);
}

void	p_error_exit(char *err)
{
	perror(err);
	exit(FAILURE);
}

void	close_fds(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}

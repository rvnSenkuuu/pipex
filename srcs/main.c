/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:05:52 by tkara2            #+#    #+#             */
/*   Updated: 2024/08/09 16:58:40 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fds[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		print_err(E_USAGE);
	if (!envp[0])
		print_err(E_ENV);
	if (pipe(fds) < 0)
		return (perror("Pipe: "), FAILURE);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork pid1: "), FAILURE);
	if (pid1 == 0)
		first_child(fds, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork pid2: "), FAILURE);
	if (pid2 == 0)
		second_child(fds, argv, envp);
	close_fds(fds);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (SUCCESS);
}

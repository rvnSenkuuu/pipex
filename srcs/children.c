/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:55:13 by tkara2            #+#    #+#             */
/*   Updated: 2024/08/09 16:58:51 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	first_child(int *fds, char *argv[], char *envp[])
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile < 0)
		return (perror("Open infile: "), exit(FAILURE));
	if (dup2(infile, STDIN_FILENO) < 0)
		return (perror("Dup2 infile: "), exit(FAILURE));
	if (dup2(fds[1], STDOUT_FILENO) < 0)
		return (perror("Dup2 fds[1]: "), exit(FAILURE));
	close_fds(fds);
	close(infile);
	exec_cmd(argv[2], envp);
}

void	second_child(int *fds, char *argv[], char *envp[])
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		return (perror("Open file: "), exit(FAILURE));
	if (dup2(fds[0], STDIN_FILENO) < 0)
		return (perror("Dup2 fds[0]: "), exit(FAILURE));
	if (dup2(outfile, STDOUT_FILENO) < 0)
		return (perror("Dup2 outfile: "), exit(FAILURE));
	close_fds(fds);
	close(outfile);
	exec_cmd(argv[3], envp);
}

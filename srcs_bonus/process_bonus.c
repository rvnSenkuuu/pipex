/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:05:17 by tkara2            #+#    #+#             */
/*   Updated: 2024/08/18 16:56:36 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	first_process(char *argv[])
{
	int	infile;
	int	index;

	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		index = 3;
		handle_here_doc(argv[2]);
	}
	else
	{
		index = 2;
		infile = open(argv[1], O_RDONLY);
		if (infile < 0)
			p_error_exit("Open infile: ");
		if (dup2(infile, STDIN_FILENO) < 0)
			p_error_exit("Dup2 infile: ");
		close(infile);
	}
	return (index);
}

void	child_process(char *cmd, char *envp[])
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) < 0)
		p_error_exit("Pipe child process: ");
	pid = fork();
	if (pid < 0)
		p_error_exit("Fork child process: ");
	if (pid == 0)
	{
		if (dup2(fds[1], STDOUT_FILENO) < 0)
			p_error_exit("Dup2 fds[0] child process: ");
		close_fds(fds);
		exec_cmd(cmd, envp);
	}
	else
	{
		if (dup2(fds[0], STDIN_FILENO) < 0)
			p_error_exit("Dup2 fds[1] child process: ");
		close_fds(fds);
	}
}

static int	handle_outfile(int argc, char *argv[])
{
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
		return (open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644));
	else
		return (open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644));
}

void	last_process(int argc, char *argv[], char *envp[])
{
	int		outfile;
	pid_t	pid;

	outfile = handle_outfile(argc, argv);
	if (outfile < 0)
		p_error_exit("Open outfile: ");
	pid = fork();
	if (pid < 0)
		p_error_exit("Fork last process: ");
	if (pid == 0)
	{
		if (dup2(outfile, STDOUT_FILENO) < 0)
			p_error_exit("Dup2 last process outfile: ");
		close(outfile);
		exec_cmd(argv[argc - 2], envp);
	}
	close(outfile);
}

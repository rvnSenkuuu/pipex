/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:41:41 by tkara2            #+#    #+#             */
/*   Updated: 2024/08/18 16:59:27 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static int	handle_tmpfile(char *file, char flag)
{
	int	tmpfile;

	tmpfile = 0;
	if (flag == 'C')
	{
		tmpfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (tmpfile < 0)
			p_error_exit("Open here_doc tmp file: ");
	}
	else if (flag == 'O')
	{
		tmpfile = open(file, O_RDONLY, 0644);
		if (tmpfile < 0)
			p_error_exit("Open here_doc tmp file: ");
	}
	return (tmpfile);
}

static void	here_doc(char *limiter, int *fds)
{
	int		tmpfile;
	char	*file;
	char	*line;

	file = HERE_DOC_TMP;
	tmpfile = handle_tmpfile(file, 'C');
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			close_fd_exit(fds[1], tmpfile);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			close_fd_exit(fds[1], tmpfile);
		}
		write(tmpfile, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(tmpfile);
	tmpfile = handle_tmpfile(file, 'O');
	close(tmpfile);
	unlink(file);
}

void	handle_here_doc(char *limiter)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) < 0)
		p_error_exit("Pipe here_doc: ");
	pid = fork();
	if (pid < 0)
		p_error_exit("Pipe here_doc: ");
	if (pid == 0)
	{
		close(fds[0]);
		here_doc(limiter, fds);
	}
	else
	{
		if (dup2(fds[0], STDIN_FILENO) < 0)
			p_error_exit("Dup2 fds[0] here_doc: ");
		close_fds(fds);
		wait(NULL);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:49:53 by tkara2            #+#    #+#             */
/*   Updated: 2024/08/15 11:45:54 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../lib/libft/includes/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# define SUCCESS 0
# define FAILURE 1
# define HERE_DOC_TMP	".here_doc.tmp"

# define E_USAGE	"Error\nUsage: ./pipex infile cmd1 cmd2 ...cmdn outfile"
# define E_HERE_DOC_USAGE "Error\nUsage:\
./pipex here_doc limiter cmd1 cmd2 ...cmdn outfile"
# define E_ENV	"Error\nEnvironment variable is NULL"

void	print_err(char *s_err);
void	p_error_exit(char *err);
void	close_fds(int *fds);
void	exec_cmd(char *cmd, char *envp[]);
void	child_process(char *cmd, char *envp[]);
int		first_process(char *argv[]);
void	last_process(int argc, char *argv[], char *envp[]);
void	handle_here_doc(char *limiter);

#endif

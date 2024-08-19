/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:05:29 by tkara2            #+#    #+#             */
/*   Updated: 2024/08/16 14:23:50 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft/includes/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# define SUCCESS 0
# define FAILURE 1

# define E_USAGE	"Error\nUsage: ./pipex infile cmd1 cmd2 outfile"
# define E_ENV	"Error\nEnvironment variable is NULL"

void	print_err(char *s_err);
void	close_fds(int *fds);
void	exec_cmd(char *cmd, char *envp[]);
void	first_child(int *fds, char *argv[], char *envp[]);
void	second_child(int *fds, char *argv[], char *envp[]);

#endif

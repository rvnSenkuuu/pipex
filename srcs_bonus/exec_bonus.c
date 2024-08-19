/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:33:13 by tkara2            #+#    #+#             */
/*   Updated: 2024/08/16 14:27:03 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static char	*get_env_path(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (&envp[i][0]);
		i++;
	}
	return (NULL);
}

static char	*get_cmd_path(char *cmd, char *envp[])
{
	int		i;
	char	*env_path;
	char	*cmd_exec;
	char	*full_path;
	char	**cmd_path;

	i = 0;
	env_path = get_env_path(envp);
	cmd_path = ft_split(env_path, ':');
	while (cmd_path[i])
	{
		full_path = ft_strjoin(cmd_path[i], "/");
		cmd_exec = ft_strjoin(full_path, cmd);
		if (access(cmd_exec, F_OK & X_OK) == 0)
			return (cmd_exec);
		free(cmd_exec);
		i++;
	}
	free(cmd_path);
	return (cmd);
}

void	exec_cmd(char *cmd, char *envp[])
{
	char	*cmd_path;
	char	**cmd_arg;

	cmd_arg = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(cmd_arg[0], envp);
	if (execve(cmd_path, cmd_arg, envp) < 0)
	{
		ft_free_doubletab(cmd_arg);
		perror("Execve: ");
	}
}

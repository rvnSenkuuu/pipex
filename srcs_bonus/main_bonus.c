/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:48:52 by tkara2            #+#    #+#             */
/*   Updated: 2024/08/15 11:46:37 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	i;

	if (!envp)
		print_err(E_ENV);
	if (argc < 5)
		print_err(E_USAGE);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0 && argc < 6)
		print_err(E_HERE_DOC_USAGE);
	i = first_process(argv);
	while (i < argc - 1)
		child_process(argv[i++], envp);
	last_process(argc, argv, envp);
	i = 0;
	while (i < argc - 1)
	{
		wait(NULL);
		i++;
	}
	unlink(HERE_DOC_TMP);
	return (SUCCESS);
}

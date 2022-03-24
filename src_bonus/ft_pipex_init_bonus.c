/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:16:24 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/24 00:09:49 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_set_pipex_null(t_pipex *pipex)
{
	pipex->argc = 0;
	pipex->argv = NULL;
	pipex->argv = NULL;
	pipex->envp = NULL;
	pipex->cmds = NULL;
	pipex->cmdpath = strdup("");
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->is_hd = 0;
}

void	ft_pipex_init(t_pipex *pipex, int argc, char **argv, char **envp)
{
	ft_set_pipex_null(pipex);
	if (ft_strncmp("here_doc", argv[1], 9) == 0 && argc >=6)
	{
		pipex->is_hd = 1;
		pipex->limiter =argv[2];
	}
	else
		pipex->infile = argv[1];
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->n_cmds = argc - (3 + pipex->is_hd);
	pipex->outfile = argv[argc - 1];
	ft_get_cmds(pipex);
	ft_get_path(pipex);
}

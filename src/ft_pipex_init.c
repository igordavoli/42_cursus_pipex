/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:16:24 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 22:33:20 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_set_pipex_null(t_pipex *pipex)
{
	pipex->argc = 0;
	pipex->argv = NULL;
	pipex->argv = NULL;
	pipex->envp = NULL;
	pipex->cmds = NULL;
	pipex->cmdpath = NULL;
	pipex->infile = NULL;
	pipex->outfile = NULL;
}

void	ft_pipex_init(t_pipex *pipex, int argc, char **argv, char **envp)
{
	ft_set_pipex_null(pipex);
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->infile = argv[1];
	pipex->n_cmds = argc - 3;
	pipex->outfile = argv[pipex->n_cmds + 2];
	ft_get_cmds(pipex);
	ft_get_path(pipex);
}

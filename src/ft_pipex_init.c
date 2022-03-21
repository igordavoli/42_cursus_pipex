/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:16:24 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 00:33:04 by idavoli-         ###   ########.fr       */
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
	pipex->curr_in_fd = -1;
	pipex->out_fd = -1;
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
	pipex->curr_in_fd = open("infile", O_RDONLY);
	pipex->out_fd = open(pipex->outfile, O_WRONLY | O_CREAT, 0666);
}

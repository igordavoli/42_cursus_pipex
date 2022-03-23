/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:44:50 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/22 23:36:36 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	partial_print(t_pipex *pipex);

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	ft_check_args(argc, argv);
	ft_pipex_init(&pipex, argc, argv, envp);
	partial_print(&pipex);
	ft_exec_cmds(&pipex);
	ft_free_pipex(&pipex);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:44:50 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 22:46:41 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	partial_print(t_pipex *pipex);

static void	ft_check_argv(char **argv, int argc)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit_pipex(NULL, "cannot open in file!", 1, 0);
	close(fd);
	if (access(argv[argc - 1], F_OK) == -1)
	{
		fd = open(argv[argc - 1], O_CREAT, 0666);
		if (fd == -1)
			ft_exit_pipex(NULL, "cannot create out file!", 1, 0);
		close(fd);
	}
}

void	ft_check_args(int argc, char **argv)
{
	if (argc != 5)
		ft_exit_pipex(NULL, "invalid number os arguments!", 1, 0);
	ft_check_argv(argv, argc);
}

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

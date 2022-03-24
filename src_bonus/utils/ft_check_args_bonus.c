/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:36:54 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/24 00:10:47 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static void	ft_check_argv_hd(char **argv, int argc)
{
	int	fd;

	if (access(argv[argc - 1], F_OK) == -1)
	{
		fd = open(argv[argc - 1], O_CREAT, 0666);
		if (fd == -1)
			ft_exit_pipex(NULL, "cannot create out file!", 1, 0);
		close(fd);
	}
}

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
	if (argc < 5)
		ft_exit_pipex(NULL, "invalid number os arguments!", 1, 0);
	if (ft_strncmp("here_doc", argv[1], 9) == 0 && argc >=6)
		ft_check_argv_hd(argv, argc);
	else
		ft_check_argv(argv, argc);
}

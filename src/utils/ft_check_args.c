/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:36:54 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/22 23:37:27 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

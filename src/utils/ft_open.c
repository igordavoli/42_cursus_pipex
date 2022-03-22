/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:28:37 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 21:15:52 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_open(t_pipex *pipex, char *file, int oflag)
{
	int	fd;

	fd = open(file, oflag);
	if (fd == -1)
		ft_exit_pipex(pipex, ft_strjoin("cannot open file: ", file), 1, 1);
	return (fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 01:45:52 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 00:40:41 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_pipex(t_pipex *pipex)
{
	int	i;
	int	j;

	if (pipex->cmds)
	{
		i = 0;
		while (pipex->cmds[i])
		{
			j = 0;
			while (pipex->cmds[i][j])
				free(pipex->cmds[i][j++]);
			free(pipex->cmds[i]);
			i++;
		}
		free(pipex->cmds);
	}
	if (pipex->cmdpath)
		free(pipex->cmdpath);
}
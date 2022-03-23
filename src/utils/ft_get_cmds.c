/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:14:31 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/22 22:52:43 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_check_aps(t_pipex *pipex)
{
	int	i;
	int	j;
	int	n_aps;

	i = 1;
	while (pipex->argv[i])
	{
		n_aps = 0;
		j = 0;
		while (pipex->argv[i][j])
			if (pipex->argv[i][j++] == 39)
				n_aps++;
		if (n_aps % 2)
			ft_exit_pipex(pipex, ft_strjoin("all apostrophes must be closed: ",
					pipex->argv[i]), 1, 1);
		i++;
	}
}

void	ft_get_cmds( t_pipex *pipex)
{
	int	i;

	ft_check_aps(pipex);
	pipex->cmds = (char ***)malloc(((pipex->n_cmds + 1) * sizeof(char **)));
	pipex->cmds[pipex->n_cmds] = NULL;
	i = 0;
	while (i < pipex->n_cmds)
	{
		pipex->cmds[i] = ft_split2(pipex->argv[i + 2], ' ');
		pipex->cmds[i][0] = ft_strjoin2("/", pipex->cmds[i][0], 0, 1);
		i++;
	}
}

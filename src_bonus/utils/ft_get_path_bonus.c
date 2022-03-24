/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:18:04 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/23 22:32:45 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static char	**ft_get_paths(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH=", pipex->envp[i], 5))
		i++;
	return (ft_split(pipex->envp[i], ':'));
}

static void	ft_set_path(t_pipex *pipex, char **path_list)
{
	int		i;
	int		j;
	char	*wholename;

	i = 0;
	while (pipex->cmds[i])
	{
		j = 0;
		while (path_list[j])
		{
			wholename = ft_strjoin(path_list[j++], pipex->cmds[i][0]);
			if (access(wholename, F_OK) == 0)
			{
				free(pipex->cmds[i][0]);
				pipex->cmds[i][0] = wholename;
				break ;
			}
			free(wholename);
		}
		i++;
	}
}

void	ft_get_path(t_pipex *pipex)
{
	int		i;
	char	**path_list;

	path_list = ft_get_paths(pipex);
	ft_set_path(pipex, path_list);
	i = 0;
	while (path_list[i])
		free(path_list[i++]);
	free(path_list);
}

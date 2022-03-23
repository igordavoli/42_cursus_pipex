/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:18:04 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/23 00:07:29 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_set_cmdpath(t_pipex *pipex)
{
	int		i;

	i = 0;
	while (pipex->cmds[i])
	{
		pipex->cmds[i][0] = ft_strjoin2(pipex->cmdpath, pipex->cmds[i][0], 0, 1);
		i++;
	}
}

static char	**ft_get_paths(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH", pipex->envp[i], 4))
		i++;
	return (ft_split(pipex->envp[i], ':'));
}

static int ft_find_path(t_pipex *pipex, char **path_list, int i )
{
	char	*path;
	int		j;

	j = 0;
	while(path_list[j])
	{
		path = ft_strjoin(path_list[j], pipex->cmds[i][0]);
		if (access(path, F_OK) == 0)
		{
			free(pipex->cmdpath);
			pipex->cmdpath = ft_strdup(path_list[j]);
			break ;
		}
		free(path);
		path = NULL;
		j++;
	}
	if (path)
		free(path);
	return (0);
}

void	ft_get_path(t_pipex *pipex)
{
	int		i;
	char	**path_list;

	path_list = ft_get_paths(pipex);
	i = 0;
	while (!(*pipex->cmdpath) && pipex->cmds[i] )
	{
		ft_find_path(pipex, path_list, i);
		i++;
	}
	i = 0;
	while (path_list[i])
		free(path_list[i++]);
	free(path_list);
	ft_set_cmdpath(pipex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:18:04 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 00:38:05 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_set_cmdpath(t_pipex *pipex)
{
	int		i;
	char	*swp;
	char	*swp2;

	swp = pipex->cmdpath;
	pipex->cmdpath = ft_strjoin(pipex->cmdpath, "/");
	free(swp);
	i = 0;
	while (pipex->cmds[i])
	{
		swp2 = pipex->cmds[i][0];
		pipex->cmds[i][0] = ft_strjoin(pipex->cmdpath, pipex->cmds[i][0]);
		free(swp2);
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

void	ft_get_path(t_pipex *pipex)
{
	int		i;
	char	**path_list;
	char	*path;
	char	*cmd;

	path_list = ft_get_paths(pipex);
	cmd = ft_strjoin("/", pipex->cmds[0][0]);
	i = 0;
	while (path_list[i])
	{
		path = ft_strjoin(path_list[i], cmd);
		if (access(path, F_OK) == 0)
		{
			pipex->cmdpath = ft_strdup(path_list[i]);
			break ;
		}
		free(path);
		free(path_list[i++]);
	}
	while (path_list[i])
		free(path_list[i++]);
	free(path_list);
	free(path);
	free(cmd);
	ft_set_cmdpath(pipex);
}
